#include <stdio.h>

void swap(int a[], int x, int y)
{
	int temp = a[x];
	a[x] = a[y];
	a[y] = temp;
}

int main()
{
	//Legge l'array
	int n;
	int a[10000];

	scanf("%d", &n);

	int i;
	for(i=0; i<n; i++) scanf("%d", &a[i]);
	
	//Lo inverte
	for(i=0; i<(n/2); i++) swap(a, i, n-i-1);

	//Lo stampa
	for(i=0; i<n; i++) printf("%d\n", a[i]);
	
	return 0;
}
