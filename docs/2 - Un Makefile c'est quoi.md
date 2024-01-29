# 🤔 Un Makefile, c'est quoi ?

## Sommaire
1. [Introduction](#introduction)
2. [Eléments d'un Makefile](#eléments-dun-makefile)
3. [Makefile Epitech](#makefile-epitech)

## Introduction
Dans ce document vous allez découvrir / redécouvrir les Makefiles, leur fonctionnement et comment les utiliser à leur plein potentiel.

Sans plus attendre, redéfinissons ce qu'est un Makefile et à quoi servent ces fichiers

> Un Makefile est un fichier spécifique qui permet d'orchestrer la création / génération de fichiers dépendamment de certaines règles définies. Il est utilisé par la commande `make` lorsqu'elle est appelée.

*Un Makefile permet par exemple d'orchestrer la compilation de fichiers C vers **un fichier binaire** ou encore vers une **bibliothèque** ou n'importe quel autre type de fichier. Il présente l'avantage de ne pas recompiler inutilement les fichiers déjà à jour.*

Vous pouvez voir le Makefile comme la chaine de production d'une voiture. En effet, comme pour la production d'une voiture, le Makefile suit des règles précises d'un bout à l'autre de la chaine. Il passe par plusieurs étapes intermédiaires pour construire chaque partie de la voiture et fini par les assembler pour produire le fichier final (un fichier binaire, une bibliothèque...).

## Eléments d'un Makefile
Un Makefile se compose de plusieurs éléments fondamentaux : les règles, règle spéciale : *.PHONY* et enfin des variables.

### Règles
___
Les règles d'un Makefile s'écrivent avec une syntaxe spécifique:
``` Makefile
cible: dependances
	commandes à executer pour construire la cible
```

- La `cible` correspond à un nom de fichier et au nom de la règle.
- Les `dependances` correspondent à des noms de fichiers devant être présents pour pouvoir construire correctement la cible.
- Les `commandes à executer pour construire la cible` sont appelées lorsque les dépendances sont présentes et construisent le fichier désigné par `cible`.

**Comment fonctionne une règle lorsqu'elle est appelée ?**
1. `make` vérifie que les dépendances sont présentes.  Si ce n'est pas le cas, alors il appelle la règle pour construire cette dépendance et ainsi de suite.
2. Ensuite il vérifie la date des fichiers de dépendances, ainsi si ceux si sont plus récent que la dernière version du fichier  `cible`.

**Règle utilisée par défaut lors d'un appel à `make`**
Par défaut, lorsque `make` est appelée sans arguments, la **règle utilisée est `all`** si elle est définie.
Elle peut-être modifiée en définissant la nouvelle règle dans la variable spéciale `.DEFAULT_GOAL` comme suit :

``` Makefile
.DEFAULT_GOAL := ma_regle_personnalisee

ma_regle_personnalisee:
	gcc -o project_binary str.o sub.o main.o
```

### Règle spéciale .PHONY
____
La règle *.PHONY* permet de spécifier que d'autre règles ne sont pas utilisées pour construire des fichiers (*ex: clean, fclean*), dans ce cas, le nom attribué à la cible est factice et sert uniquement à donner un nom à la règle.

Quand une règle a été ajoutée à la règle *.PHONY* et qu'elle est appelée,  `make` ne vérifiera pas si la cible existe déjà et éxécutera les commandes de manière systématique.

Ajouter des règles à *.PHONY*, permet d'ajouter des règles "utilitaires" pour nettoyer un projet par exemple, lancer des tests...

Pour écrire la règle *.PHONY*, il faut procéder comme suit:
``` Makefile
.PHONY: clean fclean

clean:
	rm -f str.o
	rm -f sub.o

fclean: clean
		rm -f a.out
```

**Particularité**
Si une règle ne sert pas à compiler un fichier et qu'elle porte le même nom qu'un fichier/dossier déjà présent dans votre projet, `make` risquerait de se comporter anormalement.

*Exemple: le projet courant contient un dossier `tests`*
```
tests:
		echo "je passe tout c'est sur"
```

Lorsque `make tests` est appelé, le message `make: 'tests' is up to date.` apparaitra car le dossier existe déjà. Or dans notre cas, on ne cherche pas à créer le fichier `tests` mais simplement à exécuter une commande de manière systématique. **Il est donc important d'ajouter ce type de règles à votre *.PHONY*.**

### Variables
___
Les variables permettent, tout comme en C, de stocker des valeurs pouvant être utilisées au sein des règles.

**Particularités**
* Une fois assignée (qu'on lui à défini une valeur), une variable ne peut plus être modifiée.
* Elles sont définies en dehors des règles

Les variables ne s'écrivent pas de la même manière qu'elles s'utilisent. Voici les différentes syntaxes:
``` Makefile
.PHONY: print

# Déclaration d'une variable simple
MA_VARIABLE = hello

# Déclaration d'une variable contenant une suite de mots
MA_LONGUE_VARIABLE =  hello \
					  world \
					  how \
					  are \
					  you

# Utilisation des variables
print:
	echo $(MA_VARIABLE)
	echo $(MA_LONGUE_VARIABLE)
```

Résultat lors de la commande `make print` 
```
bash$ make print
echo hello
hello
echo hello world how are you
hello world how are you
```

## Makefile Epitech
A Epitech, dans la plupart des projets la compilation du projet s'effectue par Makefile. Celui-ci doit avoir à minima les 4 les règles suivantes :  `all`, `re`, `clean`, `fclean`.

Voici un lien vers la [documentation Makefile d'Epitech](https://intra.epitech.eu/file/Public/technical-documentations/epitech_makefile.pdf).

⚠️ N'oubliez pas d'ajouter les règles qui doivent l'être au *.PHONY* de votre Makefile.
