#include "traitement.h"
#include <stdio.h>


int lookBot(int x, int y, int tab[8][8],int myColor)
{
	int i,j;
	int othercolor;		
	if (myColor == 1) othercolor = 2;
	else othercolor = 1;

	if (x == 7 ) return 0; // blindage de bords de tableau

	if (tab[x+1][y] == othercolor) // verificarion plus complexe 
	{
		if ( x == 6) return 0 ; // blindage de bords de tableau
		for (i = x+1 ; i < 8 ; i ++)
		{
			if (tab [i][y] == 0) return 0;// cas ou n'y a rien
			if (tab [i][y] == myColor) return 1;// cas bon
		}

	} 

	return 0;
}
int lookTop(int x, int y, int tab[8][8],int myColor)
{
	int i,j;
	int othercolor;		
	if (myColor == 1) othercolor = 2;
	else othercolor = 1;

	if (x == 0 ) return 0; // blindage de bords de tableau

	if (tab[x-1][y] == othercolor) // verificarion plus complexe 
	{
		if ( x == 1) return 0 ; // blindage de bords de tableau
		for (i = x-1 ; i > 0 ; i --)
		{
			if (tab [i][y] == 0) return 0;// cas ou n'y a rien
			if (tab [i][y] == myColor) return 1;// cas bon
		}

	} 


	return 0;
}
int lookRight(int x, int y, int tab[8][8],int myColor)
{
	int i,j;
	int othercolor;		
	if (myColor == 1) othercolor = 2;
	else othercolor = 1;

	if (y == 7) return 0;// blindage de bords de tableau

	if (tab[x][y + 1] == othercolor) // verificarion plus complexe 
	{
		if ( y == 6) return 0 ; // blindage de bords de tableau
		for (i = y+1 ; i < 8 ; i ++)
		{
			if (tab [x][i] == 0) return 0;// cas ou n'y a rien
			if (tab [x][i] == myColor) return 1;// cas bon
		}

	} 

	//if (tab[x+1][y] == othercolor) return 1; // TODO

	return 0;
}
int lookLeft(int x, int y, int tab[8][8],int myColor)
{
	int i,j;
	int othercolor;		
	if (myColor == 1) othercolor = 2;
	else othercolor = 1;

	if (y == 0) return 0;// blindage de bords de tableau

	if (tab[x][y - 1] == othercolor) // verificarion plus complexe 
	{
		if ( y == 1) return 0 ; // blindage de bords de tableau
		for (i = y-1 ; i > 0 ; i --)
		{
			if (tab [x][i] == 0) return 0;// cas ou n'y a rien
			if (tab [x][i] == myColor) return 1;// cas bon
		}

	} 

	//if (tab[x+1][y] == othercolor) return 1; // TODO

	return 0;
}



void whichCaseIsOK(int myColor,int tab[8][8],int possibilities[8][8])
{
	int i,j;
	int othercolor;
	if (myColor == 1) othercolor = 2;
	else othercolor = 1;
printf("\n\n");
	for (i = 0 ; i < 8 ; i++)
	{
		for ( j = 0 ; j < 8 ; j++)
		{
			if (tab[i][j] == 0) // on regarde si il y a un pions sur la case
			{
				if (lookRight(i,j,tab,myColor)) 
					{
						printf("R : %d ; %d\n",i,j);
						possibilities[i][j] = 4;
					}
				else if (lookLeft(i,j,tab,myColor)) 
					{
						printf("L : %d ; %d\n",i,j);
						possibilities[i][j] = 4;
					}
				else if (lookBot(i,j,tab,myColor)) 
					{
						printf("B : %d ; %d\n",i,j);
						possibilities[i][j] = 4;
					}
				else if (lookTop(i,j,tab,myColor)) 
					{
						printf("T : %d ; %d\n",i,j);
						possibilities[i][j] = 4;
					}
			}
		}
	}

}




void findcase(int tab[8][8],int myColor, int tailleX,int tailleY, char *depx, char *depy){

	
	int othercolor;

	if (myColor == 1) othercolor = 2;
	else othercolor = 1;
	int possibilities[8][8] = {0};

	int x = 0;
	int y = 0;
	int i,j;
	char searchval1, searchval2;
	int fin = 0;
	int verre = 0;


	for (i = 0 ; i < 8 ; i ++)
	{
		for (j = 0 ; j < 8 ; j ++)
		{
			possibilities[i][j] = tab[i][j];
		}
	}


	whichCaseIsOK(myColor,tab, possibilities);


printf("\nmy color : %d \n\n", myColor);

	for (i = 0 ; i < 8 ; i ++)
	{
		for (j = 0 ; j < 8 ; j ++)
		{
			printf("%d ",possibilities[i][j]);
			if (possibilities[i][j] == 4)
			{
				*depx = j;
				*depy = i;
			}
		}
		printf("\n");
	}


}


void decouvrir_tab(char corps[1000], int message_len, int myColor, char *depx, char *depy){
	int i,j;
	int val = 0;
	int temp = 0;
	int cptx = 0;
	int cpty = 0;
	int cpt = 0;
	int tab[8][8] ;

	int tailleX = 0;
	int tailleY = 0;

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


	findcase(tab,myColor, tailleX,tailleY, depx, depy);

	printf("\nici, on joue\n");
}






int message_couleur(char corps[1000], int playerColor){
	if (corps[0] == 0x01)
	{
		printf ("\n je suis le joueur noir\n");
		return 1;
	}
	else if (corps[0] == 0x02)
	{
		printf("\nje suis le joueur blanc\n");
		return 2;
	}
	else printf("\ncouleur inconnu\n");


	
}

int calc_checksum (int message_type, int message_len, char corps[1000]){
	int checksum;
	int i;
	checksum = message_type;
	for (i = 0 ; i < message_len ; i++) 
	{
		checksum += corps[i];
	}
	checksum = checksum & 0x000000ff;

	return checksum;
}