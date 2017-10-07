========================================================================
                            CITYSIM PROJECT
========================================================================
Description

Citysim est un jeu de gestion de ville dans lequel le joueur aura à sa
disposition un nombre limité de ressource qu’il devra gérer afin de
pouvoir survivre, se développer et même conquérir de nouveaux
territoires. L’objectif principal ? Etendre sa domination sur un maximum
de villes mais cela ne sera pas chose facile. Contre l’IA ou face à
d’autres joueurs, l’utilisateur devra faire preuve de stratégie pour
gagner.

/////////////////////////////////////////////////////////////////////////////

Système du jeu

En tant que « patron » de sa ville, le joueur devra gérer son budget
qui servira pour bon nombres de choses à savoir marchander avec les
villes voisines pour l’acquisition de produits alimentaires (servant
notamment à nourrir la population), l’acquisition de ressources
énergétiques (électricité, pétrole…) ou encore la construction de
nouveaux bâtiments que ce soit pour le logement d’une population
croissante ou encore pour la gestion de l’alimentation (fermes, magasin),
des finances (banques) ou bien de la sécurité (commissariats, casernes,
hôpitaux…).

Au fur et à mesure de son avancé dans le jeu, le joueur, s’il se
débrouille bien, obtiendra un budget suffisant pour l’achat direct des
villes voisines qui sont à la fois là pour marchander avec vous mais
également là pour vous racheter ! Etendre son territoire donnera à
l’utilisateur un accès direct aux ressources de celles-ci et donc une plus
grande emprise sur ses concurrents.

Plusieurs autres fonctionnalités seront disponibles au cours du jeu tel que
l’arbre de compétences octroyant des bonus non négligeable ou encore un
système de contrat permettant d’avoir un échange facilité et régulier des
ressources entre la ville du joueur et les autres. Il faudra cependant faire
attention à disposer d’un budget suffisant car une fois le contrat signé, il
devra être honoré jusqu’à sa date d’expiration et si cela ne peut se faire
c’est la fin de partie !

/////////////////////////////////////////////////////////////////////////////

Classes

•	Ville
    o	Attributs
        	Id
        	Nom
        	Faction
        	Ressources
            •	Population
            •	Alimentation
            •	Energie
            •	Budget
        	Arbre de compétences
        	Arbre de constructions
        	Liste de contrats
    o	Méthodes
        	Evolution de (thread autonome basé sur le temps)
            •	Population
            •	Alimentation
            •	Energie
            •	Budget
        	Contrats
            •	Parcourir contrats
            •	Passer contrat
            •	Supprimer contrat
            •	Honorer contrat : (Ville cible, temps restant, ressource cible,
            coût, quantité) : Retour booléen (contrat honoré ou non)
            •	Valeur contrat
        	Conquête
            •	Acheter ville
            •	Changer faction
            •	Conquérir ville
        	Autogestion
            •	Vérifier ressources
        	Explorer villes autour

/////////////////////////////////////////////////////////////////////////////

