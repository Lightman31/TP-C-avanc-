
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

void sendMessage(SOCKET sock, const char *ecrit, int nbOctet);



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