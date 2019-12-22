Bonjour et bienvenue dans ce README, 

le projet ici présent est une IA qui simule un coup dans une partie d'othello contre un autre joueur.

cet IA est faite pour jouer sur un plateau de taille 8x8.
A l'origne, cet IA etait capable de jouer sur n'importe quelle tableau : de petite ou grande taille, et même de forme rectangulaire. 
Cependant, lors du tournois organisé lundi matin sur ZOOM, notre IA a montré des defaillances. Nous avons donc décidé de fixer la taille du tableau, pour simplifier l'exercie.

Il s'est avéré ensuite, que la défaillance était due à la verification du checksum. En effet, l'arbitre envoie des cheksum differents en fonction des circonstances : il peuvent avoir cette forme :"0xd2" ou bien celle ci : "0xffffffd2" : cela s'est ajouté au problèmes de connections liés à linux. A ce jour, nous n'avons toujours pas compris pourquoi il nous a été difficile de nous connecter au début du tournois.

Nous avons observé que de temps en temps, notre code réponds mal : comme si il ratait des coups. Nous ne savons pas a quoi cela est due, cela arrive environ 1 partie sur 5. Comme nous n'avons pas d'aléatoire dans notre code, et que notre IA à toujours joué contre lui même, les parties sont toujours identiques et donc, nous pensons que ces non-réponses sont dues à une communication trop rapide entre l'arbitre et notre code : nous observons que noyre code est en attente de message .

Notre IA est entièrement codé sous la distibution Linux.

Le pseudo de notre joueur est "Ligntman"

Merci de m'avoir lu, et bon courrage

GAME ON 


