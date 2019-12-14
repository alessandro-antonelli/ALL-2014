#include <stdlib.h>
#include <stdio.h>

typedef struct _nodo
{
	int dato;
	struct _nodo* sx;
	struct _nodo* dx;
} nodo;

typedef struct _cercaprof
{
	int profond;
	int trovato;
} cercaprof;

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
		else  (*radice).dx = Inserisci((*radice).dx, input);
		return radice;
	}
}

cercaprof* Profondita(nodo* radice, int cercato, int prof)
{
	if(radice == NULL)
	{
		cercaprof* valore = malloc(sizeof(cercaprof));
		(*valore).trovato = 0;
		(*valore).profond = prof;
		return valore;
	}
	else
	{
		cercaprof* valore = malloc(sizeof(cercaprof));
		if((*radice).dato == cercato)
		{
			(*valore).profond = prof;
			(*valore).trovato = 1;
		}
		else
		{
			cercaprof* valoreSX = Profondita((*radice).sx, cercato, prof+1);
			cercaprof* valoreDX = Profondita((*radice).dx, cercato, prof+1);
			(*valore).profond = prof;
			(*valore).trovato = 0;
			if((*valoreSX).trovato) { (*valore).trovato = 1; (*valore).profond = (*valoreSX).profond; }
			if((*valoreDX).trovato) { (*valore).trovato = 1; (*valore).profond = (*valoreDX).profond; }
			free(valoreSX); free(valoreDX);
		}
		return valore;
	}
}

int main()
{
	int n;
	scanf("%d", &n);

	nodo* radice = NULL;

	int i;
	int input;
	for(i=0; i<n; i++)
	{
		scanf("%d", &input);
		radice = Inserisci(radice, input);
	}

	scanf("%d", &input);
	while(input >= 0)
	{
		cercaprof* risp = Profondita(radice, input, 0);
		if((*risp).trovato == 1) printf("%d\n", (*risp).profond);
		else printf("NO\n");
		free(risp);

		scanf("%d", &input);
	}

	return 0;
}
