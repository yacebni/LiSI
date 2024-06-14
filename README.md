# SAE C BOUANANI DIAS MAYRAND
## Name
LiSI (Libre Spreadsheet IUT)

## Description
LiSI est un logiciel permettant de modifier un annuaire. Son interface est affichee sur la console et se veut simple a prendre en main.
Il permet a l'utilisateur de modifier son annuaire librement et d'enregistrer les modifications si il est satifait de ces dernieres.
LiSI a ete realise dans le cadre d'un projet de groupe encadre de premiere annee de BUT informatique.

## Installation
Il est possible d'installer LiSI de plusieurs facons. 
Vous pouvez l'installer depuis le depot distant sous forme d'une archive zip ou tar ,puis extraire les dossiers de l'archive.
Lien vers la forge : ```https://forge.univ-lyon1.fr/sae-c/sae-c-bouanani-dias-mayrand```
Vous pouvez aussi l'installer avec Git.
Pour l'intaller avec Git vous aurez besoin d'avoir installe Git au prealable.
Pour completer l'installation de LiSI avec Git, suivez ces etapes:
1- Ouvrez une fenetre Git Bash
2- Clonez le dossier sur le depot distant
```
git clone https://forge.univ-lyon1.fr/sae-c/sae-c-bouanani-dias-mayrand.git
```
3- L'installation est completee ,vous pouvez utiliser LiSI.

## Usage
Pre-requis a l'utilisation:
    -Un compilateur C (de preference CodeBlocks)
    -Doxygen

Pour compiler et lancer LiSI sur une machine Windows:
Ouvrez le dossier contenant les fichiers de LiSI puis rendez vous dans bin puis Debug et ouvrez le fichier exe.


Pour compiler et lancer LiSI sur une machine Linux:
Ouvrez un terminal de commande dans le dossier contenant les fichiers de LiSI.
Puis effectuez les commandes suivantes:
```
gcc -Wall main.c functions.c -o LiSI
```

## Documentation
La documentation est disponible dans le dossier html du dossier doxygen de LiSI. 
Pour acceder a la documentation il vous sera seulement necessaire d'ouvrir index.html dans votre navigateur (Mozilla,Google,Edge,etc).
Si vous avez installe CodeBlocks, vous pourrez aussi y acceder en ouvrant le fichier cbp dans CodeBlocks.
Il vous suffira alors d'aller dans le menu DoxyBlocks et de cliquer sur "Run HTML".

## Auteurs
- BOUANANI Yacine
- MAYRAND Hugo
- DIAS ARANTES Ricardo

## License
Copyleft strict
