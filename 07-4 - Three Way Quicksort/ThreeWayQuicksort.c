#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void swap(int a[], int i, int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

void quicksort( int a[], int sx, int dx ) {
	int perno, pivot;
 	if( sx < dx )
	{
		pivot = sx + (rand() % (dx-sx + 1));

		int valore = a[pivot];
		swap(a, pivot, dx);
		int i = sx; int k = sx; int p = dx;
	
		while(i < p)
		{
			if(a[i] < a[dx]) swap(a, i++, k++);
			else	if(a[i] == a[dx]) swap(a, i, --p);
				else i++;
		}

		int m;
		if(p-k < dx-p+1) m = p-k;
		else m = dx-p+1;

		int count;
		for(count = 0; count <= m-1; count++) swap(a, k+count, dx-m+1+count);
	
		quicksort(a, sx, k-1);
		quicksort(a, dx-p+k+1, dx);
    
	}

}

int legge(int **a, int *len) {

  int i;
  scanf("%d", len);
  if(*len <= 0) return 1;

  *a = (int *) malloc(*len * sizeof(int));
  if(*a == NULL) return 1;

  for( i = 0; i < *len; i++ ) 
	  scanf("%d", (*a)+i);
  
  return 0;

}

int main() {
  
  int i, n, *A;

  if( legge(&A, &n)) return 1;

  srand(time(NULL));
  quicksort(A, 0, n-1);
  
  for( i = 0; i < n; i++ ) 
    printf("%d ", A[i]);
	
  return 0;
}
