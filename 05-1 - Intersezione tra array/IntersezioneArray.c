#include <stdio.h>
#include <stdlib.h>

int ContaElComuni(int* a, int dima, int* b, int dimb)
{
	int i, j, trovato;
	int conteggio = 0;
	for(i=0; i<dima; i++)
	{
		j=0; trovato = 0; 
		while(j<dimb && !trovato)
		{
			if(a[i] == b[j]) trovato = 1;
			j++;
		}
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
