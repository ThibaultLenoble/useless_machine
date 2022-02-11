
# The Useless Machine
## Projet réalisé par Ramus, Valentin et Thibault
### Avec la participation de jean-philippe

## La génèse du projet :

L'origine du projet viens d'une invention appelée la useless machine qui est un mini challenge pour ceux qui veulent apprendre l'éléctronique.
L'une des principales différences de notre projet est que nous n'utilisons pas d'intérrupteur à l'extérieur pour activer et désactiver le système.

## Le fonctionnement :

La première étape est celle de la photorésistance. Par défaut cette dernière capte la lumière, cependant lorsque l'obstruons, elle va envoyer un signal au servomoteur.
Ce servoteur va activer un bras mécanique relié au couvercle de la boite qui lui permettra de s'ouvrir.

Une fois la trappe ouverte, vous pourrez essayer de mettre un objet à l'intérieur. Si vous y arrivez le capteur ultrasonic détéctera l'objet et enveira un signal au micro-controleur pour envoyer un message sur slack via le service IFTTT.

Concrètement si vous avez bien compris le fonctionnement, vous comprendrenez que cette boitre ne sert... à rien;

## Les composants :

Voici la liste des composants d'on vous aurez besoin :

* Un micro-contrôleur ESP32-WROOM-32 (avec son cable de chargement)
* Un capteur ultrasonic HC-SR04
* Une photo-résistance
* Une petite breadboard (nous avons utilisé une 17x10 pin mais on a réllement besoin que de la moitié)
* Un servomoteur SG90
* Les cables pour les différents raccordements

## Schémas électronique :

![alt text](https://github.com/RamusAs/useless_machine/blob/master/img/image%201.png?raw=true)
![alt text](https://github.com/RamusAs/useless_machine/blob/master/img/image%203.png?raw=true)

## Galerie :

![alt text](https://github.com/RamusAs/useless_machine/blob/master/img/incline.png?raw=true)
![alt text](https://github.com/RamusAs/useless_machine/blob/master/img/cote.png?raw=true)
![alt text](https://github.com/RamusAs/useless_machine/blob/master/img/travers.png?raw=true)
