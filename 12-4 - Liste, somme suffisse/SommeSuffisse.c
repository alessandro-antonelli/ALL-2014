#include <stdio.h>
#include <stdlib.h>

typedef struct _el
{
	int dato;
	struct _el* next;
} el;

void Stampa(el* l)
{
	if(l != NULL)
	{
		printf("%d ", (*l).dato);
		Stampa((*l).next);
	}
	else printf("\n");
}

int SommeSuffisse(el* u)
{
	if(u != NULL)
	{
		return (*u).dato + SommeSuffisse((*u).next);
	} else return 0;
}

void SostituisciSommeSuffisse(el* testa)
{
	el* curr = testa;
	while(curr != NULL)
	{
		int somma = SommeSuffisse((*curr).next);
		(*curr).dato = somma;
		curr = (*curr).next;
	}
}

int main()
{
	int n;
	scanf("%d", &n);

	int input;
	scanf("%d", &input);
	el* testa = malloc(sizeof(el));
	(*testa).dato = input;
	(*testa).next = NULL;
	n--;
	el* curr = testa;

	while(n>0)
	{
		scanf("%d", &input);
		(*curr).next = malloc(sizeof(el));
		curr = (*curr).next;
		(*curr).dato = input;
		(*curr).next = NULL;
		n--;
	}

	Stampa(testa);

	SostituisciSommeSuffisse(testa);

	Stampa(testa);

	return 0;
}
