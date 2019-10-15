#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>


typedef struct chainList{
	char val;
	int passage ;
	struct chainList *d ,*b;
}t_chain;


/************************************************************
* TITLE : createChainList
* Creator : Léo 
* PARAMETRE : size of the list
* RETURN : premier élément de la listé crée
* PURPOSE : crée une liste chainé de la taille désiré
*************************************************************/
t_chain *createChainList() // Fonction qui prend en parametre la taille de la liste chainee que l'on souhaite creer.
{
	t_chain *a, *ab, *aba, *abac, *abaca;

	a=(t_chain*)malloc(sizeof(t_chain));
	a->val='a';
	a->d=NULL;
	a->b=NULL;

	ab=(t_chain*)malloc(sizeof(t_chain));
	ab->val='b';
	ab->d=NULL;
	ab->b=NULL;

	aba=(t_chain*)malloc(sizeof(t_chain));
	aba->val='a';
	aba->d=NULL;
	aba->b=NULL;

	abac=(t_chain*)malloc(sizeof(t_chain));
	abac->val='c';
	abac->d=NULL;
	abac->b=NULL;

	abaca=(t_chain*)malloc(sizeof(t_chain));
	abaca->val='a';
	abaca->d=NULL;
	abaca->b=NULL;

	a->d = ab;
	ab->d = aba;
	aba->d = abac;
	abac->d = abaca;

return a;
}

/************************************************************
* TITLE : lengthOfChain
* Creator : Léo 
* PARAMETRE : premier maillon de la liste chainé
* RETURN : nombre de maillon dans la liste
* PURPOSE : compte et retourne la taille de la liste chainé
*************************************************************/
/*int lengthOfChain(t_chain *firstElem)
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
}*/

/************************************************************
* TITLE : readChaine
* Creator : Léo 
* PARAMETRE : premier maillon de la liste chainé
* RETURN : empty
* PURPOSE : affiche la valeur stocké dans chaque élément de la liste chainé, dans l'ordre 
*************************************************************/
void readChaine(t_chain *firstElem)
{
	t_chain *nextElem = firstElem;
	int fin = 0;
	printf("%c", nextElem->val);
	while (fin == 0)
	{
		nextElem = nextElem->d;
		if (nextElem->d == NULL)
			fin = 1;
		printf("%c", nextElem->val);
	}

	printf ("\n");

}

/************************************************************
* TITLE : insertElm
* Creator : Léo 
* PARAMETRE : position de l'élément à insérer, maillon à insérer, premier maillon de la liste
* RETURN : premier élément de la liste
* PURPOSE : ajouter un élément dans la liste chainé à la position souhaité
*************************************************************/
/*t_chain *insertElm(int position, t_chain *elm2insert, t_chain *firstElem)
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
*/


/************************************************************
* TITLE : Main
* Creator : langage C 
* PARAMETRE : empty
* RETURN : code de terminaison
* PURPOSE : call functions, and be main
*************************************************************/
int main(){

	t_chain *firstElem = createChainList();

	readChaine(firstElem);

}
