#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int i, int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

void SelectionSort(int* a, int len)
{
	int i, j;
	for(i=0; i<len; i++)
	{
		int min = i;
		for(j=i+1; j<len; j++) if(a[j] < a[min]) min = j;
		swap(a, i, min);
	}
}

int main()
{
	int len, i;
	scanf("%d", &len);
	int* a = malloc(len * sizeof(int));
	for(i=0; i<len; i++) scanf("%d", &a[i]);

	SelectionSort(a, len);

	for(i=0; i<len; i++) printf("%d\n", a[i]);
	free(a);

	return 0;
}
