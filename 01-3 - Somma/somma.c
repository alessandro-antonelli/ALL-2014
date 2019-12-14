#include <stdio.h>

int main()
{
	//Lettura interi e somma progressiva
	int somma = 0;
	int ultimo = -1;
	while(ultimo != 0)
	{
		scanf("%d", &ultimo);
		somma = somma + ultimo;
	}
	
	//Stampa somma
	printf("%d\n", somma);
	return 0;
}
