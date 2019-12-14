#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b)
{
	int uno = *((int*) a);
	int due = *((int*) b);
	if(abs(uno%2) == abs(due%2)) //parità uguale
	{
		if(abs(uno%2) == 0) //entrambi pari
			return uno - due;
		else //entrambi dispari
			return due - uno;
	}
	else //parità diversa
	{
		if(abs(uno%2) == 0) //primo pari secondo dispari
			return -1;
		else //primo dispari secondo pari
			return 1;
	}
}

int main()
{
	int len;
	scanf("%d", &len);

	int* array = malloc(len * sizeof(int));

	int i;
	for(i=0; i<len; i++) scanf("%d", &array[i]);

	qsort(array, len, sizeof(int), compare);

	for(i=0; i<len; i++) printf("%d\n", array[i]);
	
	return 0;
}
