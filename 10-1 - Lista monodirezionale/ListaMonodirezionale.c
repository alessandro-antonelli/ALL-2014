#include <stdio.h>
#include <stdlib.h>

typedef struct _el
{
	int key;
	struct _el* next;
} el;

void StampaContrario(el* testa)
{
	if(testa != NULL)
	{
		StampaContrario((*testa).next);
		printf("%d\n", (*testa).key);
	}
}

int main()
{
	int n;
	scanf("%d", &n);

	el* testa = malloc(sizeof(el));
	el* curr = testa;

	int i;
	for(i=0; i<n; i++)
	{
		scanf("%d", &((*curr).key));
		if(i==n-1) (*curr).next = NULL;
		else (*curr).next = malloc(sizeof(el));

		curr = (*curr).next;
	}

	StampaContrario(testa);

	return 0;
}
