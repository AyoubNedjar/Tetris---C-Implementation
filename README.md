# Tetris

## Description

Voici le projet de Tetris . C'est un jeu qui se joue tout seul et qui est implémenté au tour par tour pour l'instant.

Nous avons une classe Game qui fera la modification du jeu .

La classe Bag contient un sac de briques avec lequel le joueur va jouer et qui sont choisies de manière aléatoire. 

La classe View s'occupe de l'affiche console pour que l'utilisateur puisse voir le board ainsi que les 
commandes qu'il doit taper et les informations sur le score, niveau, ...

La classe CheckRules s'occupe de vérifier que les conditions de victoire ne sont pas atteintes . 

L'Observer de nos actions serra la classe Contrôler et ceux qui sont Observable sont les déplacements 
qui sont effectués dans le Game . Comme par exemple la méthode rotate() ou moveBrick() . 

Dans la classe CommonData , nous retrouvons les énumérations utilisées . Comme le sens de rotation ou l'état du jeu .

Le répertoire avec les Brick contient toutes les briques avec lequel le joueur joue.

Pour faire run le projet , nous devons séléctionner le projet selector 
et ensuite dans la compilation choisir : Minimum Size Release .
