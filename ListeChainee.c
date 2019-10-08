#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


typedef struct chainList{
	int val;
	struct chainList *p ,*n;
}t_chain;

t_chain *createChainList(int sizeList) // Fonction qui prend en parametre la taille de la liste chainee que l'on souhaite creer.
{
	t_chain *start, *last, *newElm;
	int i=0;

	start=(t_chain*)malloc(sizeof(t_chain));
	start->val=1;
	start->n=NULL;
	start->p=NULL;

	last = start;
	
	for(i=2; i<sizeList+1; i++)
	{
		newElm=(t_chain*)malloc(sizeof(t_chain));
		newElm->val=i;
		newElm->n=NULL;
		last->n = newElm;
		newElm->p = last;
		last = newElm;
	}

return start;

}


int lengthOfChain(t_chain *firstElem)
{
	int cpt = 1;
	t_chain *nextElem = firstElem;
	int fin = 0;
	printf("%d\n", nextElem->val);
	while (fin == 0)
	{
		nextElem = nextElem->n;
		if (nextElem->n == NULL)
			fin = 1;
		cpt++;
	}
	return cpt;
}

void readListFirstToLast(t_chain *firstElem)
{
	t_chain *nextElem = firstElem;
	int fin = 0;
	printf("%d\n", nextElem->val);
	while (fin == 0)
	{
		nextElem = nextElem->n;
		if (nextElem->n == NULL)
			fin = 1;
		printf("%d\n", nextElem->val);
	}

}

void readListLastToFirst(t_chain *firstElem)
{
	t_chain *nextElem = firstElem;
	int fin = 0;
	while (fin == 0)
	{
		nextElem = nextElem->n;
		if (nextElem->n == NULL)
			fin = 1;
	}
	fin = 0;
	printf("%d\n", nextElem->val);
	while (fin == 0)
	{
		nextElem = nextElem->p;
		if (nextElem->p == NULL)
			fin = 1;
		printf("%d\n", nextElem->val);
	}

}


t_chain *insertElm(int position, t_chain *elm2insert, t_chain *firstElem)
{


	if (position < 0) position = 0;
	else if (position > lengthOfChain(firstElem)) position = lengthOfChain(firstElem);
	else position = 0;

	//printf("position = %d\n", position);

	int i=0;

	start=(t_chain*)malloc(sizeof(t_chain));
	start->val=1;
	start->n=NULL;
	start->p=NULL;

	last = start;
	
	for(i=2; i<sizeList+1; i++)
	{
		newElm=(t_chain*)malloc(sizeof(t_chain));
		newElm->val=i;
		newElm->n=NULL;
		last->n = newElm;
		newElm->p = last;
		last = newElm;
	}

return start;



	return firstElem;

}
int main(){

	t_chain *firstElem = createChainList(10);


	printf("taille de la chaine = %d\n", lengthOfChain(firstElem));

	printf("first t0 last\n");
	readListFirstToLast(firstElem);

	printf("last t0 first\n");
	readListLastToFirst(firstElem);

	firstElem = insertElm(5, firstElem, firstElem);

	printf("first t0 last\n");
	readListFirstToLast(firstElem);


}
