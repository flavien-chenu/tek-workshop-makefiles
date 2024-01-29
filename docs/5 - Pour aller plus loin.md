# 🚀 Pour aller plus loin

## Créer sa propre version de la règle `.c` ➡️ `.o`

Vous vous souvenez de la règle modèle qui transformera n'importe quel produit `n.o` à partir de `n.c` ? Créez votre propre version de cette règle dès à présent. Elle peut-être définie directement comme suit :

1. De même que pour une règle classique, il lui faut une **cible, ici il s'agira de `%.o`** (le `%` représente "n'importe quoi", c'est dire que cette règle sera utilisée pour construire tous les fichiers `.o`).
2. Mais il faut aussi **une dépendance**, car un fichier `.o` nécessite un fichier `.c`, mais alors comment faire ? Et bien de même que pour la cible, le **nom sera `%.c`**.
3. Ainsi on à la règle `%.o: %.c`.
4. Ajoutons maintenant la commande `gcc` à la règle.  Ah, mais par contre comment on récupère le nom du `.o` a créer ? Et celui du `.c` de base ? Il existe 2 variables automatiques ([doc ici](https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html)) utilisable dans ce contexte :
	1. `$@` correspond au nom du fichier `.o` à construire
	2. `$<` correspond à la première dépendance passée
	
5. Maintenant, il faut appeler la commande `$(CC)` avec les bons arguments ! **A vous de jouer !** 