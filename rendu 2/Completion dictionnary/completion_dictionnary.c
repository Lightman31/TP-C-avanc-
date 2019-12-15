#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define SIZE_PREFIX 1024

/**************************************************************

	The completion dictionary function uses chained lists to 
	store given elements in a smart way: it links words together 
	without linking letters that they already have in common.
	The dictionnary must start with at least one letter and won't
	work properly with words that don't begin with said letter.

 **************************************************************/

typedef struct chainedList // chained list struct.
{
	char value;
	struct chainedList *nextletter;
	struct chainedList *nextword;
}chainedL;

chainedL *chain_init(char arg) // function that initialises the chain with a given character.
{
	chainedL *chain = malloc(sizeof(chainedL));
	chain->value = arg;
	chain->nextletter = NULL;
	chain->nextword = NULL;

	return chain;
}

chainedL *word_to_chainedlist(char *str) // puts the content of a string in a chained list.
{
	chainedL *prev = NULL;
	chainedL *first = NULL;
	int string_length = strlen(str);
	chainedL *current;

	for(int i=0; i<string_length; i++)
	{
		current = chain_init(str[i]);

		if(prev!=NULL)
		{
			prev->nextletter = current;
		}
		else
		{
			first = current;
		}

		prev = current;
	}

	chainedL *last_letter = chain_init('$'); // To add the $ at the end of chained word
	current->nextletter =last_letter;


	return first;
}

void addWord(chainedL *current, char* word_to_add) //adds the current chained list containing word to the dictionary
{
	int string_length = strlen(word_to_add);
	int i;

	for(i=0; i<string_length; i++)
	{
		if(word_to_add[i]!=current->value)
			{break;}
		current = current->nextletter;
	}

	if (current->nextword == NULL) 
	{
		chainedL *chain_to_add = word_to_chainedlist(word_to_add + i);
		current->nextword = chain_to_add;
	}
	else
	{
		addWord(current->nextword, word_to_add + i);
	}
}


void display_word(chainedL *list) //displays a word from the dictionary
{
	while(list->value!='$')
	{
		printf("%c", list->value);
		list = list->nextletter;
	}
	printf("\n");
}

void display_both(char *prefix, chainedL *list) //displays a word that has a common prefix with another word in the dictionary.
{
	char original_prefix[SIZE_PREFIX];
	strcpy(original_prefix, prefix);
	printf("%s", prefix);
	display_word(list);

	while (list != NULL)
	{
		if (list->nextword)
		{
			display_both(prefix, list->nextword);
		}

		strcat(prefix, &(list->value));
		list = list->nextletter;
	}

	strcpy(prefix, original_prefix);
}

void display(chainedL *current) // displays the content of the dictionary
{
	char prefix[SIZE_PREFIX] = { 0 };
	display_both(prefix, current);
}


int main(void)
{
	chainedL *dico_auto;

	dico_auto = word_to_chainedlist("MY"); 
	addWord(dico_auto, "MYTHIC");
	addWord(dico_auto, "MYTHOLOGY");

	addWord(dico_auto, "MATHS");
	addWord(dico_auto, "MYTHS");
	addWord(dico_auto, "MOSAMBIQUE");
	addWord(dico_auto, "MYTHOLOGIE");
	addWord(dico_auto, "MATHEMATIQUES");
	addWord(dico_auto, "MELANCOLIE");
	addWord(dico_auto, "MACAQUE");

	display(dico_auto);
}