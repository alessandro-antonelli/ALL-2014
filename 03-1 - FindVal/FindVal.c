#include <stdio.h>

int* FindVal(int a[], int len, int val)
{
	int* risultato = NULL;
	int i = 0;
	while(i<len && risultato == NULL)
	{
		if(a[i] == val) risultato = &a[i];
		i++;
	}
	return risultato;
}

int main()
{
	int a[10];
	int i, cercato;
	for(i=0; i<10; i++) scanf("%d", &a[i]);
	scanf("%d", &cercato);

	int* risultato = FindVal(a, 10, cercato);

	if(risultato == NULL) printf("non trovato\n");
	else printf("trovato\n");

	return 0;
}
