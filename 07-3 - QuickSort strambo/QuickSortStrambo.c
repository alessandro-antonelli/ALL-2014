#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int x, int y)
{
	int temp = a[x];
	a[x] = a[y];
	a[y] = temp;
}

int confronto(int x, int pivot)
{
	int Xdispari = x % 2;
	int Pdispari = pivot % 2;
	if(Pdispari)
	{
		if(Xdispari && x > pivot) return 1;
		else{ 	if(Xdispari && x == pivot) return 0;
			else return -1;}
	}
	else
	{
		if(!Xdispari && x < pivot) return -1;
		else{	if(!Xdispari && x == pivot) return 0;
			else return 1;}
	}
}

int Partition(int* a, int pivot, int sx, int dx)
{
	int valore = a[pivot];
	swap(a, pivot, dx);
	
	int i = sx; int j = dx-1;

	while(i <= j)
	{
		while(i <= j && confronto(a[i], valore) <= 0) i++;
		while(i <= j && confronto(a[j], valore) >= 0) j--;
		if(i < j) swap(a, i, j);
	}
	
	swap(a, dx, i);
	
	return i;
}

void QuickSortStrambo(int* a, int sx, int dx)
{
	if(sx<dx)
	{
		int perno = sx + (rand() % (dx-sx+1));
		int pivot = Partition(a, perno, sx, dx);
		
		QuickSortStrambo(a, sx, pivot-1);
		QuickSortStrambo(a, pivot+1, dx);
	}
}

int main()
{
	int len, i;
	scanf("%d", &len);
	int* a = malloc(len * sizeof(int));
	for(i=0; i<len; i++) scanf("%d", &a[i]);

	srand(time(NULL));
	QuickSortStrambo(a, 0, len-1);
	
	for(i=0; i<len; i++) printf("%d ", a[i]);
	free(a);

	return 0;
}
