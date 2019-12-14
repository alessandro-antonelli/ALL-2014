#include <stdio.h>
#include <stdlib.h>
#define p 999149

int n, a, b;

typedef struct _el
{
	int dato;
	struct _el* next;
} el;

int Hash(int x)
{
	return ((a*x+b) % p) % (2*n);
}

void Inserisci(el** T, int x, int* dimensioni)
{
	int pos = Hash(x);

	el* nuovo = malloc(sizeof(el));
	(*nuovo).dato = x;

	if(T[pos] == NULL) { (*nuovo).next = NULL; dimensioni[pos] = 1; }
	else { (*nuovo).next = T[pos]; dimensioni[pos]++; }
	T[pos] = nuovo;
}

int main()
{
	scanf("%d", &n);
	scanf("%d", &a);
	scanf("%d", &b);

	el** T = malloc(2*n* sizeof(el*));
	int* dimensioni = malloc(2*n* sizeof(int));

	int i;
	for(i=0; i<2*n; i++) dimensioni[i] = 0;

	for(i=0; i<n; i++)
	{
		int input;
		scanf("%d", &input);
		Inserisci(T, input, dimensioni);
	}

	int max = 0;
	int tot = 0;
	for(i=0; i<2*n; i++)
	{
		if(dimensioni[i] > 1) tot = tot + (dimensioni[i] - 1);
		if(dimensioni[i] > max) max = dimensioni[i];
	}

	printf("%d\n", max);
	printf("%d\n", tot);

	return 0;
}
