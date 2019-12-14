#include <stdio.h>
#include <stdlib.h>
#define p 999149

int a, b, n;

typedef struct _el
{
	int dato;
	struct _el* next;
} el;

typedef struct _dInt
{
	int lunghezza;
	int conflitti;
} dInt;

int Hash(int x)
{
	return ((a*x+b) % p) % (2*n);
}

int CercaLista(el* l, int x)
{
	if(l==NULL) return 0;
	else if((*l).dato == x) return 1;
	else return CercaLista((*l).next, x);
}

void Inserimento(int x, el** T, dInt* statistiche)
{
	int pos = Hash(x);

	if(T[pos] == NULL)
	{
		el* nuovo = malloc(sizeof(el));
		(*nuovo).dato = x;
		(*nuovo).next = NULL;
		T[pos] = nuovo;
		statistiche[pos].lunghezza = 1;
	}
	else
	{
		int EsisteGia = CercaLista(T[pos], x);
		if(!EsisteGia)
		{
			el* nuovo = malloc(sizeof(el));
			(*nuovo).dato = x;
			(*nuovo).next = T[pos];
			T[pos] = nuovo;
			statistiche[pos].lunghezza++;
			statistiche[pos].conflitti++;
		}
	}
}

int main()
{
	scanf("%d", &n);
	scanf("%d", &a);
	scanf("%d", &b);

	el** T = malloc(2*n* sizeof(el*));
	dInt* statistiche = malloc(2*n* sizeof(dInt));

	int i;
	for(i=0; i<2*n; i++)
	{
		statistiche[i].lunghezza = 0;
		statistiche[i].conflitti = 0;
	}

	for(i=0; i<n; i++)
	{
		int input;
		scanf("%d", &input);
		Inserimento(input, T, statistiche);
	}

	int conflitti = 0;
	int max = 0;
	int tot = 0;
	for(i=0; i<2*n; i++)
	{
		conflitti = conflitti + statistiche[i].conflitti;
		if(statistiche[i].lunghezza > max) max = statistiche[i].lunghezza;
		tot = tot + statistiche[i].lunghezza;
	}
	printf("%d\n", conflitti);
	printf("%d\n", max);
	printf("%d\n", tot);

	return 0;
}
