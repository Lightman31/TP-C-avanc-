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
	int i=0;
	int fin = 0;
	t_chain *nextElem = firstElem;
	t_chain *newElem = (t_chain*)malloc(sizeof(t_chain));
	newElem->val = elm2insert->val;
	newElem->p = NULL;
	newElem->n = NULL;

	if (position <= 0) 
	{
		firstElem->p = newElem;
		newElem->n = firstElem;
		return newElem;
	}

	else 
	{
		if (position > lengthOfChain(firstElem))
		{
			for(i=0; i<lengthOfChain(firstElem)-1; i++)
			{
				nextElem = nextElem->n;		
			}
			newElem->p = nextElem;
			nextElem->n = newElem;
		}
		else 
		{
			//printf("position = %d\n", position);

			for(i=0; i<position-1; i++)
			{
				nextElem = nextElem->n;		
			}
			//printf("next element = %d\n", nextElem->val);
			newElem->p = nextElem->p;
			newElem->n = nextElem;
			nextElem->p->n = newElem;
			nextElem->p = newElem;
			//printf("elm2insert->p = %d\n", newElem->p->val);
			//printf("elm2insert->n = %d\n", newElem->n ->val);
			//printf("next element = %d\n", nextElem->val);
		}

	}


	//printf("position = %d\n", position);


	return firstElem;

}
int main(){

	t_chain *firstElem = createChainList(10);
	t_chain *anElement;
	anElement=(t_chain*)malloc(sizeof(t_chain));
	anElement->val=14;
	anElement->n=NULL;
	anElement->p=NULL;

	//firstElem = insertElm(0, anElement, firstElem);

	printf("taille de la chaine = %d\n", lengthOfChain(firstElem));

	firstElem = insertElm(27, anElement, firstElem);
	firstElem = insertElm(6, anElement, firstElem);
	firstElem = insertElm(5, anElement, firstElem);
	firstElem = insertElm(7, anElement, firstElem);
	firstElem = insertElm(0, anElement, firstElem);
	firstElem = insertElm(-5, anElement, firstElem);
	firstElem = insertElm(7, anElement, firstElem);
	firstElem = insertElm(26, anElement, firstElem);
	firstElem = insertElm(5, anElement, firstElem);

	printf("last t0 first\n");
	readListLastToFirst(firstElem);

	printf("first t0 last\n");
	readListFirstToLast(firstElem);


}
