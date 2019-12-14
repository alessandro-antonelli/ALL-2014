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

int Altezza(nodo* radice)
{
	if(radice == NULL) return 0;
	else
	{
		int hSX = Altezza((*radice).sx);
		int hDX = Altezza((*radice).dx);
		if(hSX > hDX) return 1+hSX;
		else return 1+hDX;
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

	int h = Altezza(radice);
	printf("%d\n", h);

	return 0;
}
