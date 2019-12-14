#include <math.h>
#include <stdio.h>

int main()
{
	int numero;
	scanf("%d", &numero);
	
	int TrovatoDivisore = 0;
	int test = (int) sqrt((double) numero);
	while(test > 1 && TrovatoDivisore == 0)
	{
		if(numero % test == 0) TrovatoDivisore = 1;
		test--;
	}

	printf("%d\n", !TrovatoDivisore);
	return 0;
}
