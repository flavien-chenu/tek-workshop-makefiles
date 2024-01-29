# 🔨Un Makefile en détails

## 0 - Contexte
Admettons un projet simple en `C`, architecturé comme suit. L'objectif est de créer un fichier binaire `my_str` .

```
.
├── Makefile
├── main.c
├── strcpy.c
├── strlen.c
├── strlower.c
└── strupper.c
```


## 1 - Compilation
Super on a plein de fichiers `.c` , on veut faire un fichier `my_str`, bah c'est pas très compliqué, il suffit de faire la commande suivante :

``` bash
gcc -o my_str main.c strcpy.c strlen.c strlower.c strupper.c
```

> Super, mais c'est assez pénible à utiliser, car il faut toujours taper la commande avec tous les noms de fichier ! De plus si simplement un fichier est modifié, il faut quand même tout recompiler (sur quelques fichiers ce n'est pas problématique, mais sur un gros projet...).
>   
>  Bref, ce n'est pas la meilleure façon ! Utilisons un Makefile.


## 2 - Création du Makefile
Le Makefile doit donc compiler dans un premier temps tout les fichiers `.c` pour produire des fichiers `.o`. Enfin il compilera tous ces fichiers en un seul fichier binaire appelé `my_str`. Voici un exemple de Makefile pour ce faire:

``` Makefile
.PHONY: all
.DEFAULT_GOAL := all

all: my_str

my_str: strcpy.o strlen.o strlower.o strupper.o main.o
    gcc -o my_str strcpy.o strlen.o strlower.o strupper.o main.o

strcpy.o: strcpy.c
    gcc -o strcpy.o -c strcpy.c

strlen.o: strlen.c
    gcc -o strlen.o -c strlen.c

strlower.o: strlower.c
    gcc -o strlower.o -c strlower.c

strupper.o: strupper.c
    gcc -o strupper.o -c strupper.c

main.o: main.c
    gcc -o main.o -c main.c
```

Super, ça marche ! Voici le détail de l'enchainement :
1. `make`     > appelle la règle `my_str`
2. `my_str`  > vérifie que les fichiers `strcpy.o strlen.o strlower.o strupper.o main.o` existent (ce n'est pas le cas, donc appelle toutes les règles nécessaires)
3. `strcpy.o`, `[...].o` , `main.o` > compile chaque fichier séparément
4. Enfin retour à la règle `my_str` > compile le fichier final !
5. **Fin**

> C'est bien notre Makefile ne recompile pas inutilement et est correctement construit ! Seul bémol écrire une règle pour chaque fichier c'est assez pénible...
>
> Voyons donc comment faire un Makefile faisant exactement la même chose mais beaucoup plus simplement et qui ne répète pas des lignes pour chaque fichier à construire.


## 3 - Makefile v2
Super, mais comment faire pour compiler tous les `.o` correspondant aux fichiers `.c` ? 

> **Non ! Nous allons utiliser une règle implicite , c'est-à-dire qui est déjà fournie par `make`. Cette règle permet de transformer n'importe quel `n.c` en `n.o`**. 

Sous le capot la règle appelle la commande suivante:
``` Makefile
$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<
```

Les variables que vous voyez sont également implicites, vous pouvez trouver [leur utilité ici](https://www.gnu.org/software/make/manual/html_node/Implicit-Variables.html)

En bref, la règle produit le même comportement que:
``` Makefile
gcc -c -o fichier.o fichier.c
```

Voici donc notre nouveau Makefile après refactorisation:

``` Makefile
my_str: strcpy.o strlen.o strlower.o strupper.o main.o
    gcc -o my_str strcpy.o strlen.o strlower.o strupper.o main.o

all: my_str
```

> Il fonctionne exactement comme le précédent, mais il est beaucoup plus court n'est-ce pas ?

## 4 - Makefile v3
Parfait, mais c'est pénible d'avoir à saisir tous les `.o` à utiliser à la suite de `gcc`, comment on peut faire ?

> Nous allons établir une liste de fichiers `.c` du projet puis nous créerons la même liste mais où tous l'extension `.c` sera remplacée par l'extension `.o`.  Nous stockerons ces liste dans des variables.

Créons d'abord une variable appelée `SRC` qui va recevoir le noms de tous les fichiers `.c`. Définissons là comme suit :
```
SRC = strcpy.c \
	  strlen.c \
	  strlower.c \
	  strupper.c \
	  main.c

# SRC sera égale à : strcpy.c strlen.c strlower.c strupper.c main.c
```

Maintenant créons la seconde liste `OBJ` pour recevoir le nom de fichiers `.o`. Cette seconde variable sera basée sur la variable `SRC`. 

Voici donc comment faire pour créer cette variable :
``` Makefile
OBJ = $(SRC:.c=.o) 

# OBJ sera égale à : strcpy.o strlen.o strlower.o strupper.o main.o
```

Désormais nous pouvons réécrire notre Makefile comme suit:
``` Makefile
SRC = strcpy.c \
	  strlen.c \
	  strlower.c \
	  strupper.c \
	  main.c

OBJ = $(SRC:.c=.o)

# En applant $(OBJ) la règle implicte vue précedemment est appelée
my_str: $(OBJ)
    gcc -o my_str $(OBJ)

all: my_str
```

> Désormais, pour ajouter un fichier, il nous suffit d'ajouter un fichier à notre liste `SRC` et tout fonctionne ! Mais par contre si le nom du binaire change, il faut changer le nom de la règle ?
> 
> La réponse est oui, mais il y a un autre moyen de faire ça plus simplement !

## 5 - Makefile v4
> On va utiliser ce truc, là... Vous savez ce truc...  pour stocker des valeurs qu'on peut changer facilement ...

Effectivement, nous allons à nouveau utiliser des variables et dans un contexte encore différent.

On va définir le nom du binaire à créer dans la variable `NAME` comme suit:
```
NAME = my_str
```

Désormais notre règle `my_str` peut être modifiée pour devenir:
```
$(NAME): $(OBJ)
    gcc -o my_str $(OBJ)

all: $(NAME)
```
