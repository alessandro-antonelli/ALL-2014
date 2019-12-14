#include <stdio.h>
#include <stdlib.h>

typedef struct _el
{
	int key;
	struct _el* next;
	struct _el* prev;
} el;

int main()
{
	int n;
	scanf("%d", &n);

	int input;
	scanf("%d", &input);

	//Creazione della lista
	el* l = malloc(sizeof(el));
	(*l).key = input;
	(*l).next = NULL;
	(*l).prev = NULL;
	n--;

	//Append degli altri elementi;
	for(; n>0; n--)
	{
		scanf("%d", &input);
		el* new = malloc(sizeof(el));
		(*new).key = input;
		(*new).prev = l;
		(*new).next = NULL;
		(*l).next = new;
		l = new;
	}

	//Stampa al contrario
	while(l != NULL)
	{
		printf("%d\n", (*l).key);
		l = (*l).prev;
	}

	return 0;
}
