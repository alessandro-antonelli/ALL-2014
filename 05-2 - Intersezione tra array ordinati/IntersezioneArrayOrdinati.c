#include <stdio.h>
#include <stdlib.h>

int RicercaBinaria(int cercato, int* a, int sx, int dx)
{
	if(sx == dx)
	{
		if(a[sx] == cercato) return 1;
		else return 0;
	}
	else
	{
		int centro = (dx+sx)/2;
		if(cercato <= a[centro]) return RicercaBinaria(cercato, a, sx, centro);
		else return RicercaBinaria(cercato, a, centro+1, dx);
	}
}

int ContaElComuni(int* a, int dima, int* b, int dimb)
{
	int i, trovato;
	int conteggio = 0;
	for(i=0; i<dima; i++)
	{
		trovato = RicercaBinaria(a[i], b, 0, dimb-1);
		if(trovato) conteggio++;
	}
	
	return conteggio;
}

int main()
{
	int i;
	int dima;
	scanf("%d", &dima);
	int* a = malloc(dima * sizeof(int));
	for(i=0; i<dima; i++) scanf("%d", &a[i]);
	
	int dimb;
	scanf("%d", &dimb);
	int* b = malloc(dimb * sizeof(int));
	for(i=0; i<dimb; i++) scanf("%d", &b[i]);

	int comuni = ContaElComuni(a, dima, b, dimb);
	free(a); free(b);

	printf("%d\n", comuni);

	return 0;
}
