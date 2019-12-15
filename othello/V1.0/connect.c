

#include"main.h"


int message_couleur(char corps[1000], int playerColor)
{
	if (corps[0] == 0x01)
	{
		printf ("\n je suis le joueur noir");
	}
	else if (corps[0] == 0x02)
	{
		printf("\nje suis le joueur blanc");
	}
	else printf("\ncouleur inconnu");


	return playerColor;
}



