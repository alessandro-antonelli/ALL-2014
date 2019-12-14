#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* product(char *str, int k)
{
	int len = strlen(str);
	char* risultato = malloc(((k*len) + 1)*sizeof(char));
	int i;

	for(i=0; i<len*k; i++) risultato[i] = str[i % len];
	risultato[k*len] = '\0';

	return risultato;
}

int main()
{
	char stringa[1001];
	int fattore;
	scanf("%s", stringa);
	scanf("%d", &fattore);
	
	char* prodotto = product(stringa, fattore);

	printf("%s\n", prodotto);

	return 0;
}
