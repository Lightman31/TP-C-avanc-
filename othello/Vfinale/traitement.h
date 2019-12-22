
#ifndef TRAITEMENT_H_INCLUDED
#define TRAITEMENT_H_INCLUDED

#define SYNCRO 0x55
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


typedef struct tab{
	char val;
	struct tab *p ,*n;
}t_chain;

int message_couleur(char corps[1000], int playerColor);
int calc_checksum (int message_type, int message_len, char corps[1000]);
void decouvrir_tab(char corps[1000], int message_len, int myColor, char *depx, char *depy);
void findcase(int tab[8][8],int myColor, int tailleX,int tailleY, char *depx, char *depy);
void whichCaseIsOK(int myColor,int tab[8][8],int possibilities[8][8]);
int lookRight(int x, int y, int tab[8][8], int myColor);
int lookLeft(int x, int y, int tab[8][8], int myColor);
int lookBot(int x, int y, int tab[8][8], int myColor);
int lookTop(int x, int y, int tab[8][8], int myColor);
int lookDiagBottomRight(int x, int y, int tab[8][8], int myColor);
int lookDiagTopLeft(int x, int y, int tab[8][8], int myColor);
int lookDiagTopright(int x, int y, int tab[8][8], int myColor);
int lookDiagBotLeft(int x, int y, int tab[8][8], int myColor);
void whereIsBest(int tab[8][8],char *depx, char *depy);
int valAbslo(int i);


#endif // OUTILS_H_INCLUDED