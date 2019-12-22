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
		for (i = x-1 ; i >= 0 ; i --)
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
		for (i = y-1 ; i >= 0 ; i --)
		{
			if (tab [x][i] == 0) return 0;// cas ou n'y a rien
			if (tab [x][i] == myColor) return 1;// cas bon
		}

	} 


	return 0;
}





int lookDiagBottomRight(int y, int x, int tab[8][8],int myColor) // looks done
{
	//printf("\n entree dans BOTLEFT : ");
	int i,j;
	int othercolor;	
	int plusgpetit = 0;	
	if (myColor == 1) othercolor = 2;
	else othercolor = 1;

	if (x == 7 | y == 7 | x == 6 | y == 6) return 0; // blindage de bords de tableau

	//printf("x : %d, y : %d\n",x, y);
	//printf("x : %d, y : %d\n",x, 7 - y);

	if ( 7-x < 7-y ) plusgpetit = 7-x;
	else plusgpetit = 7-y;

	//printf("\n entree dans BOTLEFT : taille : %d\n",plusgpetit);
	if (tab[y + 1][x+1] == othercolor) // verificarion plus complexe 
	{
		if ( plusgpetit == 1) return 0 ; // blindage de bords de tableau
	//printf("\n entree dans testsBOTLEFT \n");
		for (i = 1 ; i <= plusgpetit ; i ++)
		{
			//printf("%d ; %d = %d | ", x - i , y + i , tab [y + i][x - i]);
			if (tab [y + i][x + i] == 0) return 0;// cas ou n'y a rien
			if (tab [y + i][x + i] == myColor) return 1;// cas bon
		}

	} 
	return 0;
}


int lookDiagTopLeft(int y, int x, int tab[8][8],int myColor) 
{
	//printf("\n entree dans BOTLEFT : ");
	int i,j;
	int othercolor;	
	int plusgpetit = 0;	
	if (myColor == 1) othercolor = 2;
	else othercolor = 1;

	if (x == 0 | y == 0 | x == 1 | y == 1) return 0; // blindage de bords de tableau


	if ( x < y ) plusgpetit = x;
	else plusgpetit = y;


	if (tab[y - 1][x-1] == othercolor) // verificarion necessaire 
	{
		if ( plusgpetit == 1) return 0 ; // blindage de bords de tableau
	//printf("\n entree dans testsBOTLEFT \n");
		for (i = 1 ; i <= plusgpetit ; i ++)
		{
			//printf("%d ; %d = %d | ", x - i , y + i , tab [y + i][x - i]);
			if (tab [y - i][x - i] == 0) return 0;// cas ou n'y a rien
			if (tab [y - i][x - i] == myColor) return 1;// cas bon
		}

	} 

	return 0;
}

int lookDiagTopright(int y, int x, int tab[8][8],int myColor) 
{
	//printf("\n entree dans BOTLEFT : ");
	int i,j;
	int othercolor;	
	int plusgpetit = 0;	
	if (myColor == 1) othercolor = 2;
	else othercolor = 1;

	if (x == 7 | y == 0 | x == 6 | y == 1) return 0; // blindage de bords de tableau

	printf("x : %d, y : %d\n",x, y);
	printf("dx : %d, dy : %d\n",7-x, y);

	if ( 7-x < y ) plusgpetit = 7-x;
	else plusgpetit = y;

	//printf("\n entree dans BOTLEFT : taille : %d\n",plusgpetit);
	if (tab[y - 1][x+1] == othercolor) // verificarion plus complexe 
	{
		if ( plusgpetit == 1) return 0 ; // blindage de bords de tableau
	//printf("\n entree dans testsBOTLEFT \n");
		for (i = 1 ; i <= plusgpetit ; i ++)
		{
			printf("TR : %d ; %d = %d | ", x + i , y - i , tab [y - i][x + i]);
			if (tab [y - i][x + i] == 0) return 0;// cas ou n'y a rien
			if (tab [y - i][x + i] == myColor) return 1;// cas bon
		}

	} 

	return 0;
}
int lookDiagBotLeft(int y, int x, int tab[8][8],int myColor) // tobedouing
{
	//printf("\n entree dans BOTLEFT : ");
	int i,j;
	int othercolor;	
	int plusgpetit = 0;	
	if (myColor == 1) othercolor = 2;
	else othercolor = 1;

	if (x == 0 | y == 7 | x == 1 | y == 6) return 0; // blindage de bords de tableau

	//printf("x : %d, y : %d\n",x, y);
	//printf("x : %d, y : %d\n",x, 7 - y);

	if ( x < 7-y ) plusgpetit = x;
	else plusgpetit = 7-y;

	//printf("\n entree dans BOTLEFT : taille : %d\n",plusgpetit);
	if (tab[y + 1][x-1] == othercolor) // verificarion plus complexe 
	{
		if ( plusgpetit == 1) return 0 ; // blindage de bords de tableau
	//printf("\n entree dans testsBOTLEFT \n");
		for (i = 1 ; i <= plusgpetit ; i ++)
		{
			//printf("%d ; %d = %d | ", x - i , y + i , tab [y + i][x - i]);
			if (tab [y + i][x - i] == 0) return 0;// cas ou n'y a rien
			if (tab [y + i][x - i] == myColor) return 1;// cas bon
		}

	} 

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
						possibilities[i][j] = 4;
					}
				else if (lookLeft(i,j,tab,myColor)) 
					{
						possibilities[i][j] = 4;
					}
				else if (lookBot(i,j,tab,myColor)) 
					{
						possibilities[i][j] = 4;
					}
				else if (lookTop(i,j,tab,myColor)) 
					{
						possibilities[i][j] = 4;
					}
				else if (lookDiagBottomRight(i,j,tab,myColor)) 
					{
						printf("DBR : %d ; %d\n",i,j);
						possibilities[i][j] = 4;
					}
				else if (lookDiagTopLeft(i,j,tab,myColor)) 
					{
						printf("DTL : %d ; %d\n",i,j);
						possibilities[i][j] = 4;
					}
				else if (lookDiagBotLeft(i,j,tab,myColor)) 
					{
						printf("DBL : %d ; %d\n",i,j);
						possibilities[i][j] = 4;
					}
				else if (lookDiagTopright(i,j,tab,myColor)) 
					{
						printf("DTR : %d ; %d\n",i,j);
						possibilities[i][j] = 4;
					}
			}
		}
	}

}

int valAbslo(int i)
{
	if (i<0) return -i;
	else return i;
}

void whereIsBest(int tab[8][8],char *depx, char *depy) // calcul du poids de chaque coup
{

	int i,j;
	int best = 0;
	int cpt = 0;

	for (i = 0 ; i < 8 ; i ++)
	{
		for (j = 0 ; j < 8 ; j++)
		{
			if (tab [i][j] == 1)
			{
				cpt = cpt + 1; // on verifie que il y a bien une solution

				if ((i == 0 && j == 7) || (i == 0 && j == 0) || (i == 7 && j == 0) || (i == 7 && j == 7)) // coup absolu
					tab[i][j] = 1000;

				else if (i == 0 || i ==7 || j == 0 || j == 7) // bon coup
					tab[i][j] = (valAbslo(4-i) + valAbslo(4-j))*2 +3; 

				else if ((i == 1 && j == 6) || (i == 1 && j == 6) || (i == 6 && j ==6 ) || (i == 6 && j == 6))
					tab[i][j] = 1;

				else if ((valAbslo(4-i) + valAbslo(4-j) > 5) && i < 4 || (valAbslo(4-i) + valAbslo(4-j) > 5) && i > 3)
					tab[i][j] = 2;
								
				else 
					tab[i][j] = valAbslo(4-i) + valAbslo(4-j) +3; // calcul de coup lambda
			}
		}
	}

	for (i = 0 ; i < 8 ; i ++) // on cherche la case de plus haut poid
	{
		for (j = 0 ; j < 8 ; j++)
		{
			if (tab [i][j] > best) best = tab [i][j];
		}
	}

	printf("\nbest : %d",best);

	for (i = 0 ; i < 8 ; i ++) // on envoie
	{
		for (j = 0 ; j < 8 ; j++)
		{
			if (tab [i][j] == best) 
			{
				*depx = j;
				*depy = i;
			}
		}
	}

	if (cpt == 0) // cas sans solution
	{
		printf("\nsending : no moove left");
		*depx = -1;
		*depy = -1;
	}

}


void findcase(int tab[8][8],int myColor, int tailleX,int tailleY, char *depx, char *depy){

	
	int othercolor;

	if (myColor == 1) othercolor = 2;
	else othercolor = 1;
	int possibilities[8][8] = {0};
	int lookforbest[8][8] = {0};

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

printf("\n");
	for (i = 0 ; i < 8 ; i ++)
	{
		for (j = 0 ; j < 8 ; j ++)
		{
			printf("%d ", possibilities[i][j]);
			if (possibilities[i][j] == 4)
			lookforbest[i][j] = 1;
		}
		printf("\n");
	}

	whereIsBest(lookforbest,depx, depy);


printf("\nmy color : %d \n\n", myColor);


printf("\n");
	for (i = 0 ; i < 8 ; i ++)
	{
		for (j = 0 ; j < 8 ; j ++)
		{
			printf("%d ",lookforbest[i][j]);
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

