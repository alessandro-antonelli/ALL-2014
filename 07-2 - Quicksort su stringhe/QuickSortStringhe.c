#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void swap(char** array, int a, int b)
{
	char* temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}

int Partition(char** array, int pivot, int sx, int dx)
{
	char* mose = array[pivot]; //Mosè divide le acque tra <= e >=
	swap(array, pivot, dx);
	
	int i = sx;
	int j = dx-1;
	
	while(i <= j)
	{
		while(i <= j && (strcmp(array[i], mose) <= 0)) i++;
		while(i <= j && (strcmp(array[j], mose) >= 0)) j--;
		if(i < j) swap(array, i, j);
	}

	swap(array, i, dx);
	return i;
}

void QuickSort(char** array, int sx, int dx)
{
	if(sx<dx)
	{
		int pivot = sx + (rand() % (dx-sx+1));
		
		int perno = Partition(array, pivot, sx, dx);
	
		QuickSort(array, sx, perno-1);
		QuickSort(array, perno+1, dx);
	}
}

int main()
{
	int len, i;
	scanf("%d", &len);
	char** array = malloc(len * sizeof(char*));

	for(i=0; i<len; i++)
	{
		array[i] = malloc(101 * sizeof(char));
		scanf("%s", array[i]);
	}
	
	srand(time(NULL));
	QuickSort(array, 0, len-1);

	for(i=0; i<len; i++)
	{
		printf("%s\n", array[i]);
		free(array[i]);
	}
	free(array);

	return 0;
}
