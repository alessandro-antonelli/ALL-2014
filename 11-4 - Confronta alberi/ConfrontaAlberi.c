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
	if(radice==NULL)
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

void SegnaPercorso(nodo* radice, int* percorso, int cercato, int i)
// -1 letto elemento NULL
// -2 fine dei valori significativi
{
	if(radice == NULL) { percorso[i] = -1; percorso[i+1] = -2; }
	else
	{
		percorso[i] = (*radice).dato;
		if(cercato == (*radice).dato) percorso[i+1] = -2;
		else
		{
			if(cercato < (*radice).dato) SegnaPercorso((*radice).sx, percorso, cercato, i+1);
			else SegnaPercorso((*radice).dx, percorso, cercato, i+1);
		}
	}
}

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	//Crea gli alberi e legge i valori dei nodi
	nodo* radice1 = NULL;
	nodo* radice2 = NULL;

	int i;
	for(i=0; i<n; i++)
	{
		int input;
		scanf("%d", &input);
		radice1 = Inserisci(radice1, input);
	}
	for(i=0; i<n; i++)
	{
		int input;
		scanf("%d", &input);
		radice2 = Inserisci(radice2, input);
	}

	//Compila gli array dei percorsi seguiti nella ricerca di k
	int* percorso1 = malloc(n * sizeof(int));
	int* percorso2 = malloc(n * sizeof(int));

	SegnaPercorso(radice1, percorso1, k, 0);
	SegnaPercorso(radice2, percorso2, k, 0);

	i=0;
	int uguali=1;
	while(uguali==1 && percorso1[i] != -2 && percorso2[i] != -2)
	{
		if(percorso1[i] != percorso2[i]) uguali=0;
		i++;
	}
	printf("%d\n", uguali);

	return 0;
}
