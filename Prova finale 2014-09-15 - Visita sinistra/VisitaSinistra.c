#include <stdio.h>
#include <stdlib.h>

typedef struct _nodo
{
	int chiave;
	struct _nodo* sx;
	struct _nodo* dx;
	int L;
	int R;
} nodo;

nodo* Inserisci(nodo* radice, int input)
{
	if(radice == NULL)
	{
		nodo* nuovo = malloc(sizeof(nodo));
		(*nuovo).chiave = input;
		(*nuovo).sx = NULL;
		(*nuovo).dx = NULL;
		(*nuovo).L = 0;
		(*nuovo).R = 0;
		return nuovo;
	}
	else
	{
		if(input <= (*radice).chiave) (*radice).sx = Inserisci((*radice).sx, input);
		else (*radice).dx = Inserisci((*radice).dx, input);
		return radice;
	}
}

void VisitaSinistra(nodo* u)
{
	if((*u).sx != NULL)
	{
		VisitaSinistra((*u).sx);
		(*u).L = (*(*u).sx).L + 1;
	}
	else (*u).L = 0;

	if((*u).dx != NULL) VisitaSinistra((*u).dx);
}

void VisitaDestra(nodo* u)
{
	if((*u).dx != NULL)
	{
		VisitaDestra((*u).dx);
		(*u).R = (*(*u).dx).R + 1;
	}
	else (*u).R = 0;

	if((*u).sx != NULL) VisitaDestra((*u).sx);
}

void StampaSimmetrica(nodo* u)
{
	if(u != NULL)
	{
		StampaSimmetrica((*u).sx);
		if((*u).L > (*u).R) printf("%d\n", (*u).chiave);
		StampaSimmetrica((*u).dx);
		free(u);
	}
}

int main()
{
	int n;
	scanf("%d", &n);

	nodo* radice = NULL;

	int i;
	for(i=0; i<n; i++)
	{
		int input;
		scanf("%d", &input);
		radice = Inserisci(radice, input);
	}

	VisitaSinistra(radice);
	VisitaDestra(radice);

	StampaSimmetrica(radice);

	return 0;
}
