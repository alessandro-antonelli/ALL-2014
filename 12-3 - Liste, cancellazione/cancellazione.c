#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct _el
{
	int dato;
	struct _el* next;
} el;

int CalcolaMedia(el* l)
{
	el* curr = l;
	int somma = 0;
	int lunghezza = 0;
	while(curr != NULL)
	{
		somma = somma + (*curr).dato;
		lunghezza++;
		curr = (*curr).next;
	}
	float resto = somma/lunghezza;
	return (int) floor(resto);
}

void StampaLista(el* l)
{
	if(l != NULL)
	{
		printf("%d ", (*l).dato);
		StampaLista((*l).next);
	}
	else printf("\n");
}

el* Tronca(el* testa, int media)
{
	el* prev = NULL;
	el* curr = testa;
	
	while(curr != NULL)
	{
		if((*curr).dato > media)	
		{
			prev = curr;
			curr = (*curr).next;
			continue;
		}
		if(prev != NULL) (*prev).next = (*curr).next;
		else testa = (*curr).next;

		el* morituro = curr;
		curr = (*curr).next;
		free(morituro);
	}
	return testa;
}

int main()
{
	int n;
	scanf("%d", &n);

	int input;
	scanf("%d", &input);
	el* testa = malloc(sizeof(el));
	(*testa).dato = input;
	(*testa).next = NULL;
	el* curr = testa;
	n--;

	while(n>0)
	{
		scanf("%d", &input);
		(*curr).next = malloc(sizeof(el));
		curr = (*curr).next;
		(*curr).dato = input;
		(*curr).next = NULL;
		n--;
	}

	int media = CalcolaMedia(testa);
	printf("%d\n", media);

	StampaLista(testa);

	testa = Tronca(testa, media);

	StampaLista(testa);

	return 0;
}
