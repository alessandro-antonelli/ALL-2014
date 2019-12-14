#include <stdlib.h>
#include <stdio.h>

int SommaMassima(int* a, int len)
{
	int somma = 0;
	int sommaMax = 0;

	int i;
	
	for(i=0; i<len; i++)
	{
		if(somma < 0) somma = a[i];
		else somma = somma + a[i];

		if(somma > sommaMax) sommaMax = somma;
	}
	
	return sommaMax;
}

int main()
{
	int len, i;
	scanf("%d", &len);
	int* a = malloc(len * sizeof(int));

	for(i=0; i<len; i++) scanf("%d", &a[i]);

	int somma = SommaMassima(a, len);
	printf("%d\n", somma);

	return 0;
}
