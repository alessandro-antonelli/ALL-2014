#include <stdio.h>
#include <stdlib.h>

typedef struct _el
{
	int key;
	struct _el* next;
} el;

void LeggiContrario(el* l)
{
	if(l != NULL)
	{
		LeggiContrario((*l).next);
		printf("%d\n", (*l).key);
	}
}

int main()
{
	int len;
	scanf("%d", &len);

	int input;
	scanf("%d", &input);
	el* l = malloc(sizeof(el));
	(*l).key = input;
	(*l).next = NULL;
	el* coda = l;
	len--;

	while(len>0)
	{
		(*coda).next = malloc(sizeof(el));
		coda = (*coda).next;
		scanf("%d", &input);
		(*coda).key = input;
		(*coda).next = NULL;

		len--;
	}

	LeggiContrario(l);

	return 0;
}
