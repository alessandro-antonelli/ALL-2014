#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _nodo
{
	int chiave;
	char* valore;
	struct _nodo* sx;
	struct _nodo* dx;
} nodo;

nodo* Inserisci(nodo* radice, int chiave, char* valore)
{
	if(radice == NULL)
	{
		nodo* nuovo = malloc(sizeof(nodo));
		(*nuovo).chiave = chiave;
		(*nuovo).valore = valore;
		(*nuovo).sx = NULL;
		(*nuovo).dx = NULL;
		return nuovo;
	}
	else
	{
		if(chiave <= (*radice).chiave) (*radice).sx = Inserisci((*radice).sx, chiave, valore);
		else (*radice).dx = Inserisci((*radice).dx, chiave, valore);

		return radice;
	}
}

char* MinStringa(nodo* u, int k)
{
	if(u == NULL) return NULL;

	if((*u).chiave == k) { free((*u).valore); free(u); return NULL; }
	else
	{
		char* minSX = MinStringa((*u).sx, k);
		char* minDX = MinStringa((*u).dx, k);
		char* minFigli;

		//Eleggo la stringa minima tra le finaliste dei due figli sottoalberi

		if(minSX == NULL && minDX == NULL) minFigli = NULL; //entrambi non significativi
		else	if(minSX != NULL && minDX == NULL) minFigli = minSX; //dx non significativo
			else	if(minSX == NULL && minDX != NULL) minFigli = minDX; //sx non significativo
				else	if(strcmp(minSX, minDX) <= 0) minFigli = minSX; //entrambi significativi, scelgo il minore tra i due
					else minFigli = minDX;

		//Eleggo la stringa minima tra vincitrice dei sottoalberi e nodo stesso

		if(minFigli == NULL) return (*u).valore;
		else	if(strcmp((*u).valore, minFigli) <= 0) return (*u).valore;
			else return minFigli;

		free((*u).valore);
		free(u);
	}
}

int main()
{
	int n, k;
	scanf("%d", &n);

	nodo* radice = NULL;

	for(; n>0; n--)
	{
		int chiave;
		char* valore = malloc(101 * sizeof(char));
		scanf("%d", &chiave);
		scanf("%s", valore);

		radice = Inserisci(radice, chiave, valore);
	}

	scanf("%d", &k);
	char* stringa = MinStringa(radice, k);

	if(stringa != NULL) printf("%s\n", stringa);
	else printf("vuoto\n");

	return 0;
}
