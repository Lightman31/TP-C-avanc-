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

void affListFirstToLast(t_chain *firstElem)
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

void affListLastToFirst(t_chain *firstElem)
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


int main(){

	t_chain *firstElem = createChainList(10);

	printf("first to last\n");
	affListFirstToLast(firstElem);

	printf("last to first\n");
	affListLastToFirst(firstElem);



}
