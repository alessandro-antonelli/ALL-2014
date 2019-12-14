#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _esame
{
	char* sigla;
	int crediti;
	int difficolta;
} esame;

int OrdinAlfabetico(const void* a, const void* b)
{
	esame uno = **((esame**) a);
	esame due = **((esame**) b);

	return strcmp(uno.sigla, due.sigla);
}

int OrdinaDifficolta(const void* a, const void* b)
{
	esame uno = **((esame**) a);
	esame due = **((esame**) b);

	return uno.difficolta - due.difficolta;
}

int OrdinaCrediti(const void* a, const void* b)
{
	esame uno = **((esame**) a);
	esame due = **((esame**) b);

	return due.crediti - uno.crediti;
}

int main()
{
	int n, k;
	scanf("%d", &k);
	scanf("%d", &n);

	esame** EsamiPossibili = malloc(n * sizeof(esame*));

	int i;
	for(i=0; i<n; i++)
	{
		esame* nuovo = malloc(sizeof(esame));
		(*nuovo).sigla = malloc(101 * sizeof(char));
		scanf("%s", (*nuovo).sigla);
		scanf("%d", &((*nuovo).crediti));
		scanf("%d", &((*nuovo).difficolta));
		EsamiPossibili[i] = nuovo;
	}

	qsort(EsamiPossibili, n, sizeof(esame*), OrdinAlfabetico);
	qsort(EsamiPossibili, n, sizeof(esame*), OrdinaDifficolta);
	qsort(EsamiPossibili, n, sizeof(esame*), OrdinaCrediti);

	esame** EsamiScelti = malloc(n * sizeof(esame*));
	int TotCrediti = 0;
	int leggi = 0; int scrivi = 0;

	while(TotCrediti != k && leggi < n)
	{
		while(leggi < (n-1) && (TotCrediti + (*EsamiPossibili[leggi]).crediti) > k)
		{
			free((*EsamiPossibili[leggi]).sigla);
			free(EsamiPossibili[leggi]);
			leggi++;
		}
		TotCrediti = TotCrediti + (*EsamiPossibili[leggi]).crediti;
		EsamiScelti[scrivi] = EsamiPossibili[leggi];
		leggi++;
		scrivi++;
	}
	for(; leggi<n; leggi++)
	{
		free((*EsamiPossibili[leggi]).sigla);
		free(EsamiPossibili[leggi]);
	}
	free(EsamiPossibili);

	qsort(EsamiScelti, scrivi, sizeof(esame*), OrdinAlfabetico);

	for(i=0; i<scrivi; i++)
	{
		printf("%s\n", (*EsamiScelti[i]).sigla);
		free((*EsamiScelti[i]).sigla);
		free(EsamiScelti[i]);
	}
	free(EsamiScelti);

	return 0;
}
