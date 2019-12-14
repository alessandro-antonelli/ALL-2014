#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Ordina(const void* a, const void* b)
{
	char** a1 = (char**) a;	
	char** b1 = (char**) b;
	return strcmp(*a1, *b1);
}

int Esiste(char** a, int len, char* input)
{
	int esiste = 0;
	int i;
	for(i=0; i<len && !esiste; i++)
	{
		if(strcmp(input, a[i]) == 0) esiste = 1;
	}
	return esiste;
}

int main()
{
	char* P = malloc(101 * sizeof(char));
	char* S = malloc(101 * sizeof(char));
	int n;
	scanf("%s", P);
	scanf("%s", S);
	scanf("%d", &n);

	int distinte = 0;
	char** a = malloc(n * sizeof(char*));

	for(; n>0; n--)
	{
		char* input = malloc(101 * sizeof(char));
		scanf("%s", input);

		int doppio = Esiste(a, distinte, input);
		if(doppio) free(input);
		else { a[distinte] = input; distinte++; }
	}

	qsort(a, distinte, sizeof(char*), Ordina);

	int lenP = strlen(P);
	int lenS = strlen(S);
	for(n=0; n<distinte; n++)
	{
		char* candidata = a[n];
		int lenCand = strlen(candidata);

		int i = 0;
		int prefisso = 1;
		while(prefisso == 1 && i < lenP && i<lenCand)
		{
			if(candidata[i] != P[i]) prefisso = 0;
			i++;
		}
		if(i < lenP && i == lenCand) prefisso = 0; //Correzione per quando il candidato è più corto del prefisso

		int suffisso = 1;
		if(!prefisso)
		{
			i = 0;
			while(suffisso == 1 && i < lenS && i<lenCand)
			{
				if(candidata[lenCand - 1 - i] != S[lenS - 1 - i]) suffisso = 0;
				i++;
			}
			if(i < lenS && i == lenCand) suffisso = 0; //Correzione per quando il candidato è più corto del suffisso
		}

		if(prefisso || suffisso) printf("%s\n", candidata);
		free(candidata);
	}
	free(P);
	free(S);
	free(a);

	return 0;
}
