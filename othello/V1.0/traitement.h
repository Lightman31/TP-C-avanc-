
#ifndef TRAITEMENT_H_INCLUDED
#define TRAITEMENT_H_INCLUDED

#include"connect.h"
#include"reversi.h"


#define OKNOK_MESSAGE 0x02
#define CONNECT_MESSAGE 0x01
#define PLAYEROK_MESSAGE 0x10
#define NEWMOVE_MESSAGE 0x03
#define END_MESSAGE 0x04
#define NEXTTURN_MESSAGE 0x05
#define STATUS1_MESSAGE 0x06
#define STATUS2_MESSAGE 0x07
#define CONTROL_MESSAGE 0x08
#define PING_MESSAGE 0x11

int message_couleur(char corps[1000], int playerColor);
int calc_checksum (int message_type, int message_len, char corps[1000]);
int menu_message (SOCKET sock_client, char corps[1000], int message_type, int message_len, int playerColor);


void decouvrir_tab(char corps[1000], int message_len);


void decouvrir_tab(char corps[1000], int message_len){

	int i,j;
	int val = 0;
	int temp = 0;
	int cptx = 0;
	int cpty = 0;
	int cpt = 0;

	int tab[8][8] ;

	printf("\nici, on cherche a décripter le tableau, taille du message : %d \n message : ",message_len );

	for (i = 0 ; i < message_len ; i++ )
	printf(" %x ", corps[i]);



// LAST MOOVE
	if (corps[0] == 0xffffffff)
		printf("\nLast Moove X : no Moove");
	else
		printf("\nLast Moove X : %x", corps[0]);

	if (corps[1] == 0xffffffff)
		printf("\nLast Moove Y : no Moove");
	else
		printf("\nLast Moove Y : %x", corps[1]);

// BOARD SIZE
	printf("\nBoard Size X : %x", corps[2]);
	printf("\nBoard Size Y : %x", corps[3]);

// GET TAB

printf("\ncxwc : ");
	for (i = 4 ; i < message_len ; i++ )
	{
		printf(" %d ", corps[i]);
	}
	printf("\nblu :\n");
	cpt = 0;
	for (i = 4 ; i < message_len ; i  = i + 2 )
	{
		val = corps[i];

		tab[cpt][0] = (val & 0b11000000) >> 6 ; 
		tab[cpt][1] = (val & 0b00110000) >> 4 ; 
		tab[cpt][2] = (val & 0b00001100) >> 2 ;
		tab[cpt][3] = val & 0b00000011 ; 


		val = corps[i+1];

		tab[cpt][4] = (val & 0b11000000) >> 6 ; 
		tab[cpt][5] = (val & 0b00110000) >> 4 ; 
		tab[cpt][6] = (val & 0b00001100) >> 2 ;
		tab[cpt][7] = val & 0b00000011 ; 
		cpt ++;
	}

	for (i = 0 ; i < 8 ; i ++)
	{
		for (j = 0 ; j < 8 ; j ++)
		{
			printf ("%d ",tab[i][j]);
		}
		printf("\n");
	}

printf("\ncxwc : ");


	printf("\nici, on cherche a décripter le tableau\n");
}




int menu_message (SOCKET sock_client, char corps[1000], int message_type, int message_len, int playerColor){

	printf ("\nmenu message : ");


	if (message_type == 0x10) 
	{
		printf("Type de message : couleur");
		playerColor = message_couleur(corps, playerColor);
	}
	else if (message_type == OKNOK_MESSAGE) 
	{
		printf("Type de message : OK/NOK : il faut répondre OK (OxO1)");
	}
	else if (message_type == NEXTTURN_MESSAGE) 
	{
		printf("Type de message : NEXTTURN_MESSAGE : il faut analyser le tab");
		decouvrir_tab(corps,message_len);

	}
	else 
	{
		printf("Type de message inconnu : 0x%x\n", message_type);
	}

	return playerColor;
}





int message_couleur(char corps[1000], int playerColor){
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

int calc_checksum (int message_type, int message_len, char corps[1000]){
	int checksum;
	int i;
	checksum = message_type;
	for (i = 0 ; i < message_len ; i++) 
	{
		checksum += corps[i];
	}
	checksum = checksum & 0xffffffff;

	return checksum;
}





#endif // OUTILS_H_INCLUDED