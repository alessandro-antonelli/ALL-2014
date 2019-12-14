#include <stdio.h>
#include <stdlib.h>

typedef struct _nodo
{
	int dato;
	struct _nodo* sx;
	struct _nodo* dx;
} nodo;

nodo* Inserisci(nodo* radice, int input)
{
	if(radice == NULL)
	{
		nodo* nuovo = malloc(sizeof(nodo));
		(*nuovo).dato = input;
		(*nuovo).sx = NULL;
		(*nuovo).dx = NULL;
		return nuovo;
	}
	else
	{
		if(input <= (*radice).dato) (*radice).sx = Inserisci((*radice).sx, input);
		else (*radice).dx = Inserisci((*radice).dx, input);
		return radice;
	}
}

void StampaSimmetrica(nodo* radice)
{
	if(radice != NULL)
	{
		StampaSimmetrica((*radice).sx);
		printf("%d\n", (*radice).dato);
		StampaSimmetrica((*radice).dx);
	}
}

int main()
{
	int n;
	scanf("%d", &n);

	nodo* radice = NULL;

	while(n>0)
	{
		int input;
		scanf("%d", &input);
		radice = Inserisci(radice, input);
		n--;
	}

	StampaSimmetrica(radice);

	return 0;
}
