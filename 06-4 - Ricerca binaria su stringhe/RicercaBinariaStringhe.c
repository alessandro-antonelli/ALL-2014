#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLEN 101

int RicercaBinaria(char** a, char* stringa, int sx, int dx)
{
	int centro = (sx+dx)/2;
	int confronto = strcmp(stringa, a[centro]);
	if(sx == dx)
	{
		if(confronto == 0) return sx;
		else return -1;
	}
	else
	{
		if(confronto <= 0) return RicercaBinaria(a, stringa, sx, centro);
		else return RicercaBinaria(a, stringa, centro+1, dx);
	}
}

int main()
{
	//Allocazione array e stringhe
	int len, i;
	scanf("%d", &len);
	char** a = malloc(len * sizeof(char*));
	
	for(i=0; i<len; i++)
	{
		a[i] = malloc(MAXLEN * sizeof(char));
		scanf("%s", a[i]);
	}

	//Richieste
	char* stringa = malloc(MAXLEN * sizeof(char));
	int continuare;
	scanf("%d", &continuare);
	while(continuare)
	{
		scanf("%s", stringa);
		int result = RicercaBinaria(a, stringa, 0, len-1);
		printf("%d\n", result);
		scanf("%d", &continuare);
	}

	//Deallocazione
	free(stringa);
	for(i=0; i<len; i++) free(a[i]);
	free(a);

	return 0;
}
