#include <stdio.h>
#include <stdlib.h>

typedef struct _nodo
{
	int chiave;
	struct _nodo* sx;
	struct _nodo* dx;
	struct _nodo* padre;
	int P;
	int A;
} nodo;

nodo* Inserisci(nodo* radice, int input)
{
	if(radice == NULL)
	{
		nodo* nuovo = malloc(sizeof(nodo));
		(*nuovo).chiave = input;
		(*nuovo).sx = NULL;
		(*nuovo).dx = NULL;
		(*nuovo).P = 0;
		(*nuovo).A = 0;
		return nuovo;
	}
	else
	{
		if(input <= (*radice).chiave)
		{
			(*radice).sx = Inserisci((*radice).sx, input);
			(*(*radice).sx).padre = radice;
		}
		else
		{
			(*radice).dx = Inserisci((*radice).dx, input);
			(*(*radice).dx).padre = radice;
		}
		return radice;
	}
}

void CalcolaP(nodo* u)
{
	if(u != NULL)
	{
		if((*u).padre == NULL) (*u).P = 0; // u è la radice
		else (*u).P = (*(*u).padre).P + 1;
		CalcolaP((*u).sx);
		CalcolaP((*u).dx);
	}
}

void CalcolaA(nodo* u)
{
	if(u != NULL)
	{
		if((*u).sx == NULL && (*u).dx == NULL) (*u).A = 0; // u è una foglia
		else
		{
			//CHIAMATE RICORSIVE
			CalcolaA((*u).sx);
			CalcolaA((*u).dx);

			//RICOMBINAZIONE PER OTTENERE IL VALORE DEL NODO
			int Asx = -1;
			int Adx = -1;
			if((*u).sx != NULL) Asx = (*(*u).sx).A;
			if((*u).dx != NULL) Adx = (*(*u).dx).A;

			if(Asx == -1)
				//il nodo ha solo il figlio dx
				(*u).A = 1 + Adx;
			else
			{
				if(Adx == -1)
					//il nodo ha solo il figlio sx
					(*u).A = 1 + Asx;
				else
				{
					//il nodo ha entrambi i figli
					if(Asx < Adx) (*u).A = 1 + Asx;
					else (*u).A = 1 + Adx;
				}
			}
		}
	}
}

void StampaSimmetrica(nodo* u)
{
	if(u != NULL)
	{
		StampaSimmetrica((*u).sx);
		if((*u).A == (*u).P) printf("%d\n", (*u).chiave);
		StampaSimmetrica((*u).dx);
		free(u);
	}
}

int main()
{
	int n;
	scanf("%d", &n);

	nodo* radice = NULL;

	for(; n>0; n--)
	{
		int input;
		scanf("%d", &input);
		radice = Inserisci(radice, input);
	}

	CalcolaP(radice);
	CalcolaA(radice);

	StampaSimmetrica(radice);

	return 0;
}
