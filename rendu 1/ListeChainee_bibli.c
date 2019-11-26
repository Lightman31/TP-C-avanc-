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
	t_chain *c, *cd;
	t_chain *s, *so, *sol, *solu;
	t_chain *d, *e;

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

	c=(t_chain*)malloc(sizeof(t_chain));
	c->val='c';
	c->d=NULL;
	c->b=NULL;

	cd=(t_chain*)malloc(sizeof(t_chain));
	cd->val='d';
	cd->d=NULL;
	cd->b=NULL;

	s=(t_chain*)malloc(sizeof(t_chain));
	s->val='s';
	s->d=NULL;
	s->b=NULL;

	so=(t_chain*)malloc(sizeof(t_chain));
	so->val='o';
	so->d=NULL;
	so->b=NULL;

	sol=(t_chain*)malloc(sizeof(t_chain));
	sol->val='l';
	sol->d=NULL;
	sol->b=NULL;

	solu=(t_chain*)malloc(sizeof(t_chain));
	solu->val='u';
	solu->d=NULL;
	solu->b=NULL;

	d=(t_chain*)malloc(sizeof(t_chain));
	d->val='d';
	d->d=NULL;
	d->b=NULL;

	e=(t_chain*)malloc(sizeof(t_chain));
	e->val='e';
	e->d=NULL;
	e->b=NULL;

	a->d = ab;
	ab->d = aba;
	aba->d = abac;
	abac->d = abaca;
	abac->b = d;
	d->d =
	ab->b = c;
	c->d = cd;
	c->b= s;
	s->d = so;
	so->d = sol;
	sol->d = solu;

return a;
}

/************************************************************
* TITLE : readChaine
* Creator : Léo 
* PARAMETRE : premier maillon de la liste chainé
* RETURN : empty
* PURPOSE : affiche la valeur stocké dans chaque élément de la liste chainé, dans l'ordre 
*************************************************************/
void readChaine(t_chain *firstElem)
{
	t_chain *start;
	start = (t_chain*)malloc(sizeof(t_chain));
	start->val = firstElem->val;
	start->d = firstElem->d;
	start->b = firstElem->b;

	t_chain *nextElem = start;


	int fin = 0;
	int passage = 0; // déclaration de la variable de passage 

	while (fin == 0)
	{
		//printf("\nhey\n");
		//printf ("case : %c : passage : %d\n", nextElem->val, nextElem->passage);
		// arrivée en fin de mot
		if (nextElem->d == NULL && nextElem->b == NULL){ 
			printf("%c", nextElem->val);
			printf("\n"); // retour à la ligne
			nextElem->passage = 1;
			nextElem = start;

			if ( passage == 1)
			passage = 0; // RAZ de la variable de passage 
			else if (passage == 0 )
			fin = 1; // sortie de la boucle : fin du dico
		}

		// pas fin de mot
		else {
		
			if (nextElem->b == NULL) // cas ou il n'y a pas de case en dessous
			{
				printf("%c", nextElem->val);
				nextElem->passage = 1;
				nextElem = nextElem->d;
			}
			else if (nextElem->d->passage == 1) //cas ou il y a une case en dessous et ou on est déja passé à droite
			{
				if (nextElem->b->d != NULL)
				{
					//printf("+");
					if (nextElem->b->d->passage == 1){printf("%c", nextElem->val);}
					else {}
				} 
				else 
				printf("%c", nextElem->val);
				

				nextElem = nextElem->b;
				nextElem->passage = 1;

			}
			else if (nextElem->d->passage == 0)
			{
				printf("%c", nextElem->val);
				nextElem->passage = 1;
				nextElem = nextElem->d;
				passage = 1;
			}
		}
	}
}

/************************************************************
* TITLE : insertElm
* Creator : Léo 
* PARAMETRE : position de l'élément à insérer, maillon à insérer, premier maillon de la liste
* RETURN : premier élément de la liste
* PURPOSE : ajouter un élément dans la liste chainé à la position souhaité
*************************************************************/
t_chain *insertElm( t_chain *firstElem, char mot[])
{
	int position = 0;
	int taille = (int)strlen(mot);
	char currentLetter;

	for (int i = 0 ; i < taille ; i++)
	{
		currentLetter = mot[i];
		printf("%c\n", currentLetter);
	}
}


/************************************************************
* TITLE : Main
* Creator : langage C 
* PARAMETRE : empty
* RETURN : code de terminaison
* PURPOSE : call functions, and be main
*************************************************************/
int main(){

	//t_chain *firstElem = createChainList();

	//readChaine(firstElem);

	t_chain *firstElem = insertElm(firstElem, "hey");

}
