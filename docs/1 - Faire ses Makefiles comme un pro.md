
# 📄Faire ses Makefiles comme pro

## Sommaire
1. [Introduction](#introduction)
2. [Construire un modèle de Makefile réutilisable](#construire-un-modèle-de-makefile-réutilisable)

## Introduction
Dans ce workshop vous allez développer un modèle Makefile respectant les attentes d'Epitech et que vous pourrez très facilement réutiliser sur vos projets de 1ere et 2eme année.

Avant de commencer ce workshop, n'hésitez pas  à prendre connaissance des documents suivant :
- [Un Makefile c'est quoi](./2%20-%20Un%20Makefile%20c'est%20quoi.md)
- [Un Makefile en détails](./3%20-%20Un%20Makefile%20en%20détails.md)

Une fois que vous êtes parés et que vous avez bien compris comment fonctionne un Makefile, vous allez construire un modèle de Makefile que vous pourrez réutiliser sur vos projets en rien de temps.

## Construire un modèle de Makefile réutilisable
Pour développer rapidement, il est nécessaire qu'un Makefile puisse être opérationnel dès le début d'un projet. Pour cela, développez un Makefile réutilisable dans lequel vous n'aurez que des valeurs à donner à vos variables. 

N'hésitez pas à utiliser ce guide des [bonnes pratiques](./4%20-%20Bonnes%20pratiques.md). Pour vous aider, vous pouvez suivre les étapes détaillées dans le document [Un Makefile en détails](./3%20-%20Un%20Makefile%20en%20détails.md).

Voici une checklist pour un bon Makefile:
**Variables:**
- `SRC` qui contient la liste de tous les fichiers source `.c`
- `OBJ` pour obtenir facilement le nom des objets correspondants aux fichiers sources
- `NAME` pour définir le nom du binaire / bibliothèque à délivrer
- `CC` pour définir le compilateur à utiliser (ici on souhaite utiliser `gcc`)
- `LIBS` pour définir les bibliothèques à utiliser
- `INCLUDES` pour définir les dossiers dans lesquels chercher les en-têtes à inclure
- `CFLAGS` qui contient les drapeaux nécessaires pour une compilation qui prévient des erreurs

**Règles:**
* `all` règle principale
* `$(NAME)` correspondante aux [attentes d'Epitech](https://intra.epitech.eu/file/Public/technical-documentations/epitech_makefile.pdf)  elle doit lancer la compilation de votre bibliothèque `my`
* `clean` correspondante aux attentes d'Epitech
* `fclean` correspondante aux attentes d'Epitech
* `re` correspondante aux attentes d'Epitech
* `.PHONY` appliqué sur les règles appropriées

Lorsque vous aurez élaboré le Makefile de vos rêves, testez le dans les projets de démo proposés dans les dossiers `projects/project1` et `projects/project2`.

Si vous avez tout terminé, vous pouvez aussi aller plus loin en créant une nouvelle version de la règle qui compile les fichiers `.c` en `.o`.
