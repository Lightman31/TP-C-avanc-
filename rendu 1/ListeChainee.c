#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


typedef struct chainList{
	int val;
	struct chainList *p ,*n;
}t_chain;


/************************************************************
* TITLE : createChainList
* Creator : Léo 
* PARAMETRE : size of the list
* RETURN : premier élément de la listé crée
* PURPOSE : crée une liste chainé de la taille désiré
*************************************************************/
t_chain *createChainList(int sizeList) // Fonction qui prend en parametre la taille de la liste chainee que l'on souhaite creer.
{
	t_chain *start, *last, *newElm;
	int i=0;

	start=(t_chain*)malloc(sizeof(t_chain)); // crée le premier maillon de la chaine 
	start->val=1;
	start->n=NULL;
	start->p=NULL;

	last = start;
	
	for(i=2; i<sizeList+1; i++) // ajoute tout les autres maillons
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
* TITLE : readListFirstToLast
* Creator : Léo 
* PARAMETRE : premier maillon de la liste chainé
* RETURN : empty
* PURPOSE : affiche la valeur stocké dans chaque élément de la liste chainé, dans l'ordre 
*************************************************************/
void readListFirstToLast(t_chain *firstElem)
{
	t_chain *nextElem = firstElem;
	int fin = 0;
	printf("%d\n", nextElem->val);
	while (fin == 0) // on affiche, puis on lit le maillon le maillon suivant
	{
		nextElem = nextElem->n;
		if (nextElem->n == NULL)
			fin = 1;
		printf("%d\n", nextElem->val);
	}

}

/************************************************************
* TITLE : readListLastToFirst
* Creator : Léo 
* PARAMETRE : premier maillon de la liste chainé
* RETURN : empty
* PURPOSE : affiche la valeur stocké dans chaque élément de la liste chainé, dans l'ordre inverse
*************************************************************/
void readListLastToFirst(t_chain *firstElem)
{
	t_chain *nextElem = firstElem;
	int fin = 0; 
	while (fin == 0) // on se positionne à la fin de la chaine
	{
		nextElem = nextElem->n;
		if (nextElem->n == NULL)
			fin = 1;
	}
	fin = 0;
	printf("%d\n", nextElem->val);
	while (fin == 0) // on affiche, puis on lit le maillon précédent
	{
		nextElem = nextElem->p;
		if (nextElem->p == NULL)
			fin = 1;
		printf("%d\n", nextElem->val);
	}

}


/************************************************************
* TITLE : insertElm
* Creator : Léo 
* PARAMETRE : position de l'élément à insérer, maillon à insérer, premier maillon de la liste
* RETURN : premier élément de la liste
* PURPOSE : ajouter un élément dans la liste chainé à la position souhaité
*************************************************************/
t_chain *insertElm(int position, t_chain *elm2insert, t_chain *firstElem)
{
	int i=0;
	int fin = 0;
	t_chain *nextElem = firstElem;
	t_chain *newElem = (t_chain*)malloc(sizeof(t_chain)); // on crée une copie du maillon a ajouter
	newElem->val = elm2insert->val;
	newElem->p = NULL;
	newElem->n = NULL;

	if (position <= 0) //blindage du cas ou position <= 0 : on insère au début de la chaine
	{
		firstElem->p = newElem;
		newElem->n = firstElem;
		return newElem;
	}

	else 
	{
		if (position > lengthOfChain(firstElem)) // blindage du cas ou la position est supérieure à la taille de la chaine : on insère à la fin de la chaine
		{
			for(i=0; i<lengthOfChain(firstElem)-1; i++)
			{
				nextElem = nextElem->n;		
			}
			newElem->p = nextElem;
			nextElem->n = newElem;
		}
		else // insertion dans le cas ou la position est accepté
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


/************************************************************
* TITLE : Main
* Creator : langage C 
* PARAMETRE : empty
* RETURN : code de terminaison
* PURPOSE : call functions, and be main
*************************************************************/
int main(){

	t_chain *firstElem = createChainList(10); // création d'une chaine de 10 éléments
	t_chain *anElement;
	anElement=(t_chain*)malloc(sizeof(t_chain)); // création de l'élément à insérer
	anElement->val=42;
	anElement->n=NULL;
	anElement->p=NULL;

	//firstElem = insertElm(0, anElement, firstElem);
	printf("last t0 first\n");
	readListLastToFirst(firstElem);
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
