#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int i, int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

void InsertionSort(int* a, int len)
{
	int i, j;
	for(i=1; i<len; i++)
	{
		j=i;
		while(j > 0 && a[j-1] > a[j])
		{
			swap(a, j-1, j);
			j--;
		}
	}
}

int main()
{
	int len, i;
	scanf("%d", &len);
	int* a = malloc(len * sizeof(int));
	for(i=0; i<len; i++) scanf("%d", &a[i]);

	InsertionSort(a, len);
	for(i=0; i<len; i++) printf("%d\n", a[i]);

	return 0;
}
