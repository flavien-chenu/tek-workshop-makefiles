# 🥳 Bonnes pratiques
1. [Variables personnalisées](#variables-personnalisées)
2. [Les variables implicites / spéciales](#les-variables-implicites--spéciales)

## Variables personnalisées

### NAME
La variable `NAME` est recommandée par Epitech pour stocker le nom du fichier binaire / bibliothèque à rendre pour le projet.

*Par exemple pour le projet MyNavy*
```
NAME = my_navy
```

### INCLUDES
Vous pouvez utiliser cette variables pour stocker les répertoires dans lesquels chercher les fichiers d'en-têtes `.h`. 

*Par exemple*
```
INCLUDES = -I ./includes
```

### SRC
`SRC` devrait contenir le nom de tous les fichiers `.c` de votre projet.

*Par exemple*
``` Makefile
SRC = strcpy.c \
	  strlen.c \
	  strlower.c \
	  strupper.c \
	  main.c
```


### OBJ
La variable `OBJ` devrait contenir la liste des fichiers `.o` correspondant aux fichiers `.c`  de la liste `SRC`. Elle peut être facilement construite via:
```
OBJ = $(SRC:=.c.o)
```
### LIBS 
Vous pouvez définir cette variable si vous utilisez une ou des bibliothèques dans votre projet.

*Par exemple dans le cas d'un projet graphique utilisant la bibliothèque CSFML*
```
LIBS = -lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window
```

Ou bien si vous utilisez des bibliothèques directement dans votre projet:
```
LIBS = -L ./libs -lmy
```
## Les variables implicites / spéciales

### CC
La variable `CC` permet de définir le compilateur utilisé pour compiler les fichiers `.c`. 

> Par défaut le compilateur utilisé est `cc`, vous pouvez redéfinir cette variable sur `gcc` si vous le souhaitez.

### CFLAGS
La variable  `CFLAGS` permet de définir quels drapeaux passer au compilateur défini dans `CC`. 

**⚠️ Il est de très bonne augure d'ajouter les drapeaux suivant à la variable :**
- `-Wall` permet d'activer les avertissements généraux du compilateur
- `-Wextra` permet d'activer un niveau supérieur d'avertissement que celui offert par `-Wall`
- `-Werror` transforme tous les avertissements en erreurs empêchant alors la compilation. Cela encourage à corriger tout de suite les erreurs et ne pas les laisser s'accumuler.

``` Makefile
 CFLAGS += -Wall -Wextra -Werror
```

> Il est fortement recommandé d'ajouter à cette variable votre variable personnalisée `INCLUDES` afin qu'ils soient pris en compte lors de la compilation des objets.



**💡 Tips:**
* Pour réinitialiser le contenu d'une variable la syntaxe est la suivante : `VARIABLE := valeur`
* Pour ajouter du contenu à une variable existante, la syntaxe est la suivante : `VARIABLE += valeur`