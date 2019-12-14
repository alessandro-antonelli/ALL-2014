#include <stdio.h>
#include <stdlib.h>

typedef struct _nodo
{
	int dato;
	struct _nodo* sx;
	struct _nodo* cx;
	struct _nodo* dx;
} nodo;

nodo* Inserisci(nodo* radice, int input)
{
	if(radice == NULL)
	{
		nodo* nuovo = malloc(sizeof(nodo));
		(*nuovo).dato = input;
		(*nuovo).sx = NULL;
		(*nuovo).cx = NULL;
		(*nuovo).dx = NULL;
		return nuovo;
	}
	else
	{
		if(input < (*radice).dato) (*radice).sx = Inserisci((*radice).sx, input);
		else if((input % (*radice).dato) == 0) (*radice).cx = Inserisci((*radice).cx, input);
		else (*radice).dx = Inserisci((*radice).dx, input);
		return radice;
	}
}

int ContaTriploFiglio(nodo* radice)
{
	if(radice == NULL) return 0;
	else
	{
		int haTreFigli;
		if((*radice).sx != NULL && (*radice).cx != NULL && (*radice).dx != NULL) haTreFigli=1;
		else haTreFigli = 0;

		int SXconTreFigli = ContaTriploFiglio((*radice).sx);
		int CXconTreFigli = ContaTriploFiglio((*radice).cx);
		int DXconTreFigli = ContaTriploFiglio((*radice).dx);

		return haTreFigli + SXconTreFigli + CXconTreFigli + DXconTreFigli;
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

	int conTreFigli = ContaTriploFiglio(radice);
	printf("%d\n", conTreFigli);

	return 0;
}
