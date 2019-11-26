#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

/************************************************************
* TITLE : Main
* Creator : langage C 
* PARAMETRE : empty
* RETURN : code de terminaison
* PURPOSE : call functions, and be main
*************************************************************/
int main(){

	// translate in ASCII the string "HAL9000"
	// transform the string in lowercase
	// transform ascii number in int 

	char string[] = "HAL9000";
	char lowercaseString[] = {0};
	int taille = (int)strlen(string);
	char currentLetter;
	int i = 0;
	int stringToInt = 0;
	int multi = 1;
	printf ("%s\n",string);


			/*****************
			1
			*****************/

	taille = (int)strlen(string);
	for ( i = 0 ; i < taille ; i++)
	{
		currentLetter = string[i];
		printf("0x%x\n", currentLetter);
		
	}


			/*****************
			2 
			*****************/
	printf ("%s -> ",string);
	taille = (int)strlen(string);
	for ( i = 0 ; i < taille ; i++)
	{
		currentLetter = string[i];
		if (currentLetter <91 && currentLetter >64)
			currentLetter = currentLetter + 32;
		printf("%c", currentLetter);
		
	}

			/*****************
			3
			*****************/

	printf("\n");
	stringToInt = 0;
	taille = (int)strlen(string);
	for ( i = taille ; i >0 ; i--)
	{
		currentLetter = string[i];
		if (currentLetter > 47 && currentLetter < 58)
		{ 	
			stringToInt = stringToInt + (currentLetter-48)*multi;			
			multi = multi * 10;
		}

	}

	printf("%d\n", stringToInt);



}
