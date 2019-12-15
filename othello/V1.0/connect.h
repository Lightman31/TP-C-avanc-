
#ifndef CONNECT_H_INCLUDED
#define CONNECT_H_INCLUDED


#include"reversi.h"
#include"traitement.h"


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

int get_message_debug(SOCKET sock_client, int playerColor);
int get_message(SOCKET sock_client, int playerColor);
void sendMessage(SOCKET sock, const char *ecrit, int nbOctet);



int get_message_debug(SOCKET sock_client, int playerColor){
	char buff[1];
	char corps[1000];
	int message_len;
	int message_type;
	int checksum;

	/// SYNCHRO

	if (read ( sock_client , buff, 1) < 0) printf ("Error : When reciveing new message\n");
    if (buff[0] == 0x55) printf("\nSynchro : OK");
    else exit (0);


    /// TAILLE DU Message

	if (read ( sock_client , buff, 1) < 0) printf ("Error : When reciveing new message\n");
	printf("\nTaille du message = Ox%x = %d", buff[0], buff[0]);
	message_len = buff[0];


	/// TYPE DE MESSAGE 

	if (read ( sock_client , buff, 1) < 0) printf ("Error : When reciveing new message\n");
	message_type = buff[0];
	if (message_type == 0x10) printf("\nType de message : couleur");
	else if (message_type == 0x02) printf("\nType de message : OK/NOK : il faut répondre OK (OxO1)");
	else printf("\nType de message : %x", buff[0]);


	/// Recuperation du CORPS DU Message

	if (read ( sock_client , corps, message_len) < 0) printf ("Error : When reciveing new message\n");

	/// CHECKSUM

	if (read ( sock_client , buff, 1) < 0) printf ("Error : When reciveing new message\n");
	printf("\nCHECKSUM reçu : %x", buff[0]&0xffffffff);

	/// calcul du checksum mesuré
	checksum = calc_checksum(message_type,message_len,corps);
	printf("  ..  CHECKSUM mesuré : %x", checksum);

	if (( buff[0] & 0xffffffff ) == checksum) 
	{
		printf("\ntout est bon avec le checksum ");
	}
	else 
	{
		printf("\n\n\nPROBLEME DE CHECKSUM\n");
		exit(0);
	}


	/// tout est bon, on peut donc maintenant regarder le message 

	playerColor = menu_message(sock_client, corps, message_type, message_len, playerColor);

    return playerColor;
}

int get_message(SOCKET sock_client, int playerColor){
	char buff[1];
	char corps[1000];
	int message_len;
	int message_type;
	int checksum;

	/// SYNCHRO

	if (read ( sock_client , buff, 1) < 0) printf ("Error : When reciveing new message\n");
    if (buff[0] == 0x55) printf("\nNew message ");
    else exit (0);


    /// TAILLE DU Message

	if (read ( sock_client , buff, 1) < 0) printf ("Error : When reciveing new message\n");
	message_len = buff[0];


	/// TYPE DE MESSAGE 

	if (read ( sock_client , buff, 1) < 0) printf ("Error : When reciveing new message\n");
	message_type = buff[0];

	/*
	if (message_type == 0x10) printf("\nType de message : couleur");
	else if (message_type == 0x02) printf("\nType de message : OK/NOK : il faut répondre OK (OxO1)");
	else printf("\nType de message : 0x%x", buff[0]);
	*/

	/// Recuperation du CORPS DU Message

	if (read ( sock_client , corps, message_len) < 0) printf (" ");

	/// CHECKSUM

	if (read ( sock_client , buff, 1) < 0) printf ("Error : When reciveing new message\n");
	printf(" ");

	/// calcul du checksum mesuré
	checksum = calc_checksum(message_type,message_len,corps);

	if (( buff[0] & 0xffffffff ) == checksum) 
	{
	}
	else 
	{
		exit(0);
	}


	/// tout est bon, on peut donc maintenant regarder le message 

	playerColor = menu_message(sock_client, corps, message_type, message_len, playerColor);

    return playerColor;
}

void sendMessage(SOCKET sock, const char *ecrit, int nbOctet) {
    //Variables locales
    int l = 0;
    int fin;

    //En cas d'erreur lors de l'envoi
    if (send (sock, ecrit, nbOctet, 0) < 0)
    {
        printf ("Error : When sending new message\n");

    }

    //Affichage du message envoyé
    printf("Message sent : ");
    fin = (int) ecrit[1]+4;
    for (l = 0; l < fin ; l++) {
        printf(" %x ", ecrit[l]);
    }
    printf("\n");
}



#endif // OUTILS_H_INCLUDED