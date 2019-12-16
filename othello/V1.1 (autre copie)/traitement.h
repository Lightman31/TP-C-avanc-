
#ifndef TRAITEMENT_H_INCLUDED
#define TRAITEMENT_H_INCLUDED

#include"connect.h"
#include"reversi.h"


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
void ajElem(t_chain *firstElem, char elem);
int lengthOfChain(t_chain *firstElem);
t_chain *createChainList(int sizeList);
void readListFirstToLast(t_chain *firstElem, int TX);
void decouvrir_tab(char corps[1000], int message_len, int myColor, char *depx, char *depy);
void findcase(t_chain *firstElem,int myColor, int tailleX,int tailleY, char *depx, char *depy);








void findcase(t_chain *firstElem,int myColor, int tailleX,int tailleY, char *depx, char *depy){

	myColor = myColor+1;
	int othercolor;

	if (myColor == 1) othercolor = 2;
	else othercolor = 1;

	int x = 0;
	int y = 0;
	t_chain *nextElem = firstElem;
	t_chain *searchElem;
	char searchval1, searchval2;
	int fin = 0;
	int verre = 0;


	readListFirstToLast(firstElem,tailleX);
	printf("myColor : %d",myColor);


	while (fin == 0) // on affiche, puis on lit le maillon le maillon suivant
	{
		if (nextElem->val == myColor) 
			{
				printf("\nx = %d | y = %d",x,y);
				if (nextElem->n->val == othercolor && nextElem->n->n->val == 0 && x <=tailleX-3)
				{
					printf(" : casetrouvé");
					*depx = x+2;
					*depy = y;
					break;
				}
				else if (nextElem->p->val == othercolor && nextElem->p->p->val == 0 && x >= 2)
				{
					printf(" : casetrouvé");
					*depx = x-2;
					*depy = y;
					break;
				}
				else 
				{
					if (y < tailleY - 3)
					{
						searchElem = nextElem;
						for (verre = 0 ; verre < tailleX ; verre++)
						searchElem = searchElem->n;

						searchval1 = searchElem->val;

						for (verre = 0 ; verre < tailleX ; verre++)
						searchElem = searchElem->n;

						searchval2 = searchElem->val;

						if (searchval1 == othercolor && searchval2 == 0)
						{
							printf(" : casetrouvé");
							*depx = x;
							*depy = y + 2;
						break;
						}
					}
					else if (y > 2)
					{
						searchElem = nextElem;
						for (verre = 0 ; verre < tailleX ; verre++)
						searchElem = searchElem->p;

						searchval1 = searchElem->val;

						for (verre = 0 ; verre < tailleX ; verre++)
						searchElem = searchElem->p;

						searchval2 = searchElem->val;

						if (searchval1 == othercolor && searchval2 == 0)
						{
							printf(" : casetrouvé");
							*depx = x;
							*depy = y - 2;
						break;
						}
					}
				}
			}


		x++;
		nextElem = nextElem->n;
		if (x == tailleX)
		{
			y++;
			x = 0;
		}
		if (nextElem->n == NULL)
			fin = 1;
	}









}


void decouvrir_tab(char corps[1000], int message_len, int myColor, char *depx, char *depy){

	int i,j;
	int val = 0;
	int temp = 0;
	int cptx = 0;
	int cpty = 0;
	int cpt = 0;

	int tailleX = 0;
	int tailleY = 0;

	t_chain *firstElem = (t_chain*)malloc(sizeof(t_chain));
	firstElem->val=4;
	firstElem->n=NULL;
	firstElem->p=NULL;

	t_chain *anElement = (t_chain*)malloc(sizeof(t_chain)); 
	anElement->val=6;
	anElement->n=NULL;
	anElement->p=firstElem;
	firstElem->n=anElement;

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

	tailleX = corps[2];
	tailleY = corps[3];

// GET TAB
	for (i = 4 ; i < message_len ; i++ )
	{
		printf(" %d ", corps[i]);
	}

	printf ("liste chainee : ");

	val = corps[4];

	firstElem->val = (val & 0b11000000) >> 6 ;
	anElement->val = (val & 0b00110000) >> 4 ;
	ajElem(firstElem, (val & 0b00001100) >> 2);
	ajElem(firstElem, val & 0b00000011);



	for (i = 5 ; i < message_len ; i++ )
	{
		val = corps[i];

	ajElem(firstElem, (val & 0b11000000) >> 6);
	ajElem(firstElem, (val & 0b00110000) >> 4);
	ajElem(firstElem, (val & 0b00001100) >> 2);
	ajElem(firstElem, val & 0b00000011);

	}


	findcase(firstElem,myColor, tailleX,tailleY, depx, depy);

	printf("\nici, on joue\n");
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


/************************************************************
* TITLE : readListFirstToLast
* Creator : Léo 
* PARAMETRE : premier maillon de la liste chainé
* RETURN : empty
* PURPOSE : affiche la valeur stocké dans chaque élément de la liste chainé, dans l'ordre 
*************************************************************/
void readListFirstToLast(t_chain *firstElem, int TX)
{
	int x = 1;
	t_chain *nextElem = firstElem;
	int fin = 0;

	printf("\n%d ", nextElem->val);
	while (fin == 0) // on affiche, puis on lit le maillon le maillon suivant
	{

		x++;
		nextElem = nextElem->n;
		if (nextElem->n == NULL)
			fin = 1;
		printf("%d ", nextElem->val);
		if (x == TX)
		{
			x = 0;
			printf("\n");
		}
	}

}


/************************************************************
* TITLE : lengthOfChain
* Creator : Léo 
* PARAMETRE : premier maillon de la liste chainé
* RETURN : nombre de maillon dans la liste
* PURPOSE : compte et retourne la taille de la liste chainé
*************************************************************/
int lengthOfChain(t_chain *firstElem)
{
	int cpt = 1;
	t_chain *nextElem = firstElem;
	int fin = 0;

	while (fin == 0) // on compte les maillons
	{
		nextElem = nextElem->n;
		if (nextElem->n == NULL)
			fin = 1;
		cpt++;
	}
	return cpt;
}


/************************************************************
* TITLE : insertElm
* Creator : Léo 
* PARAMETRE : position de l'élément à insérer, maillon à insérer, premier maillon de la liste
* RETURN : premier élément de la liste
* PURPOSE : ajouter un élément dans la liste chainé à la position souhaité
*************************************************************/
void ajElem(t_chain *firstElem, char elem)
{	

	int fin = 0;
	t_chain *nextElem = firstElem;

	t_chain *newElem = (t_chain*)malloc(sizeof(t_chain)); // on crée une copie du maillon a ajouter
	newElem->val = elem;
	newElem->n = NULL;

	while (fin == 0) // on passe les maillons
	{
		nextElem = nextElem->n;
		if (nextElem->n == NULL)
			fin = 1;
	}

	nextElem->n = newElem;
	newElem->p = nextElem;

}





#endif // OUTILS_H_INCLUDED