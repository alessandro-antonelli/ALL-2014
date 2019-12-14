#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;

typedef struct _el
{
	int chiave;
	char* valore;
	struct _el* next;
} el;

void Inserisci(el** T, int pos, int chiave, char* valore)
{
	//Se nella lista trova un elemento con valore uguale all'inserendo, lo elimina
	el* prev = NULL;
	el* curr = T[pos];
	int StessaChiave = 0;	//se =1, indica che curr ha la stessa chiave dell'elemento inserendo

	while(StessaChiave == 0 && curr != NULL)
	{
		if((*curr).chiave == chiave) StessaChiave = 1;
		else { prev = curr; curr = (*curr).next; }
	}

	if(StessaChiave)
	{
		//Elimino l'elemento che ha chiave uguale all'inserendo
		if(prev != NULL) (*prev).next = (*curr).next;
		else T[pos] = (*curr).next;
		free((*curr).valore);
		free(curr);
	}

	//Inserisce <chiave, valore> nella pos-esima lista della hashtable T. Mantiene la lista ordinata alfabeticamente per valore.
	prev = NULL;
	curr = T[pos];

	while(curr != NULL && strcmp(valore, (*curr).valore) > 0)
	{
		prev = curr;
		curr = (*curr).next;
	}

	el* nuovo = malloc(sizeof(el));
	(*nuovo).chiave = chiave;
	(*nuovo).valore = valore;
	(*nuovo).next = curr;
	if(prev != NULL) (*prev).next = nuovo;
	else T[pos] = nuovo;
}

void StampaLista(el* l)
{
	if(l != NULL)
	{
		printf("%s\n", (*l).valore);
		free((*l).valore);
		StampaLista((*l).next);
		free(l);
	}
}

int Hash(int x)
{
	return (x % 109) % (2*n);
}

int main()
{
	scanf("%d", &n);

	el** T = malloc(2*n* sizeof(el*));

	int i;
	for(i=0; i<n; i++)
	{
		int chiave;
		char* valore = malloc(101 * sizeof(char));
		scanf("%d", &chiave);
		scanf("%s", valore);

		int pos = Hash(chiave);
		Inserisci(T, pos, chiave, valore);
	}

	int k;
	scanf("%d", &k);
	if(T[k] == NULL) printf("vuota\n");
	else StampaLista(T[k]);

	return 0;
}
