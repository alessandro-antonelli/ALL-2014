#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dim = 2;
int testaCoda = 0;
int fondoCoda = -1;
int cardCoda = 0;

char** VerificaRaddoppio(char** vecchio)
{
	if(cardCoda >= dim)
	{
		char** nuovo = malloc(2 * dim * sizeof(char*));

		int i;
		int indLettura = testaCoda;
		int indScrittura = 0;
		for(i=0; i<cardCoda; i++)
		{
			nuovo[indScrittura] = vecchio[indLettura];
			indScrittura = (indScrittura + 1) % (2*dim);
			indLettura = (indLettura + 1) % dim;
		}

		dim = dim * 2;
		testaCoda = 0;
		fondoCoda = cardCoda-1;

		free(vecchio);
		return nuovo;
	}
	else return vecchio;
}

char** VerificaDimezzamento(char** vecchio)
{
	if(cardCoda <= (dim/4))
	{
		char** nuovo = malloc(dim/2 * sizeof(char*));

		int i;
		int indLettura = testaCoda;
		int indScrittura = 0;
		for(i=0; i<cardCoda; i++)
		{
			nuovo[indScrittura] = vecchio[indLettura];
			indScrittura = (indScrittura + 1) % (dim/2);
			indLettura = (indLettura + 1) % dim;
		}

		dim = dim/2;
		testaCoda = 0;
		fondoCoda = cardCoda-1;

		free(vecchio);
		return nuovo;
	}
	else return vecchio;
}

int Confronta(const void* a, const void* b)
{
	char** uno = (char**) a;
	char** due = (char**) b;
	return strcmp(*uno, *due);
}

int main()
{
	char** a = malloc(2 * sizeof(char*));

	int e;
	scanf("%d", &e);

	while(e != 0)
	{
		if(e == 1)
		{
			//E' arrivato un paziente. Ci dice il nome e si accoda
			char* nome = malloc(101 * sizeof(char));
			scanf("%s", nome);

			a = VerificaRaddoppio(a);
			cardCoda++;
			fondoCoda = (fondoCoda + 1) % dim;
			a[fondoCoda] = nome;
		}
		if(e == 2 && cardCoda > 0)
		{
			//Il dottore visita il primo paziente in coda
			cardCoda--;
			free(a[testaCoda]);
			testaCoda = (testaCoda + 1) % dim;
			a = VerificaDimezzamento(a);
		}

		scanf("%d", &e);
	}

	if(cardCoda > 0)
	{
		//Sistemo in un array dove il primo è il primo
		char** nuovo = malloc(cardCoda * sizeof(char*));

		int indLettura = testaCoda;
		int indScrittura;
		for(indScrittura=0; indScrittura<cardCoda; indScrittura++)
		{
			nuovo[indScrittura] = a[indLettura];
			indLettura = (indLettura + 1) % dim;
		}
		free(a);
		a = nuovo;
	
		//Ordino
		qsort(a, cardCoda, sizeof(char*), Confronta);

		//Stampo
		for(e=0; e<cardCoda; e++)
		{
			printf("%s\n", a[e]);
			free(a[e]);
		}
	}
	printf("$\n");
	free(a);

	return 0;
}
