#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


char strget(char string[], int x1, int x2)
{
	char extrString[];
	int i = 0;
	for (i = x1 ; i<x2 ; i ++)
	{
		strcat(extrString, string[i]);
	} 
	printf("%s\n", extrString);
	return extrString;
}


int todecimal ()
{

}


void identification(char message [])
{

	int pos = 0;





}


int main ()
{
	/* message : 
	00000000 : last moov X
	00000000 : last moov Y
	00000011 : board size X
	00000011 : board size Y
	board state : 
	10010000 : 0x90
	00100100 : 0x24
	00011000 : 0x18
	00000000 : 0x00
	*/
	
	char message[] = "000000000000000000000011000000001110010000001001000001100000000000";

	printf("%s\n", message);
	identification(message);

	return 0;
}



