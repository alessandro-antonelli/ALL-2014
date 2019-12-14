#include <stdio.h>

void minmax(int a[], int len, int* min, int* max)
{
	*min = 0; *max = 0;
	int i;
	for(i=1; i<len; i++)
	{
		if(a[i] < a[*min]) *min = i;
		if(a[i] > a[*max]) *max = i;
	}
}

int main()
{
	int a[10];
	int IndMin, IndMax;

	int i;
	for(i=0; i<10; i++) scanf("%d", &a[i]);

	minmax(a, 10, &IndMin, &IndMax);
	
	printf("%d\n", IndMin);
	printf("%d\n", a[IndMin]);
	printf("%d\n", IndMax);
	printf("%d\n", a[IndMax]);
	return 0;
}
