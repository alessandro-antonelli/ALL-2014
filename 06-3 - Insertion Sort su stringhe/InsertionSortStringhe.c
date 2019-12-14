#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char** a, int i, int j)
{
	char* temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

void InsertionSort(char** a, int len)
{
	int i;
	for(i=1; i<len; i++)
	{
		int j = i;
		while(j > 0 && strcmp(a[j-1], a[j]) > 0)
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
	char** a = malloc(len * sizeof(char*));
	
	for(i=0; i<len; i++)
	{
		a[i] = malloc(101 * sizeof(char));
		scanf("%s", a[i]);
	}

	InsertionSort(a, len);

	for(i=0; i<len; i++)
	{
		printf("%s\n", a[i]);
		free(a[i]);
	}
	free(a);
	
	return 0;
}
