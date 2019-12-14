#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _record
{
	char* nome;
	char* numero;
	struct _record* next;
} record;

int Hash(char* nome, int len)
{
	int i = 0;
	unsigned int somma = 0;
	unsigned int lastchar = nome[0];

	while(lastchar)
	{
		somma = somma + lastchar;
		i++;
		lastchar = nome[i];
	}
	return (somma % len);
}

void Inserisci(record** rubrica, int pos, char* nome, char* numero)
{
	record* prev = NULL;
	record* curr = rubrica[pos];

	while(curr != NULL && (strcmp(nome, (*curr).nome) > 0))
	{
		prev = curr;
		curr = (*curr).next;
	}

	//Ora siamo sempre nel caso in cui l'elemento va inserito tra prev e curr
	record* nuovo = malloc(sizeof(record));
	(*nuovo).nome = nome;
	(*nuovo).numero = numero;
	(*nuovo).next = curr;
	if(prev != NULL) (*prev).next = nuovo;
	else rubrica[pos] = nuovo;
}

void Stampa(record* l)
{
	if(l != NULL)
	{
		printf("%s %s\n", (*l).nome, (*l).numero);
		free((*l).nome);
		free((*l).numero);
		Stampa((*l).next);
		free(l);
	}
}

int main()
{
	int n, k;
	scanf("%d", &n);

	record** rubrica = malloc(2*n* sizeof(record*));

	int i;
	for(i=0; i<n; i++)
	{
		char* nome = malloc(101 * sizeof(char));
		char* numero = malloc(21 * sizeof(char));
		scanf("%s", nome);
		scanf("%s", numero);
		int pos = Hash(nome, 2*n);
		Inserisci(rubrica, pos, nome, numero);
	}

	scanf("%d", &k);
	Stampa(rubrica[k]);

	return 0;
}
