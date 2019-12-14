#include <stdio.h>
#include <stdlib.h>

typedef struct _el
{
	int key;
	struct _el* next;
} el;

int Cerca(el* l, int cercato)
{
	int posizione = 0;
	int risultato = -1;

	while(risultato == -1 && l != NULL)
	{
		if((*l).key == cercato) risultato = posizione;
		l = (*l).next;
		posizione++;
	}

	return risultato;
}

el* MTF(el* l, int pos)
{
	el* spostare = l;
	el* preSpostare = l;
	int i;
	for(i=0; i<pos; i++) spostare = (*spostare).next;
	for(i=0; i<pos-1; i++) preSpostare = (*preSpostare).next;
	el* postSpostare = (*spostare).next;

	(*spostare).next = l;
	(*preSpostare).next = postSpostare;

	return spostare;
}

int main()
{
	int n;
	scanf("%d", &n);

	int input;
	scanf("%d", &input);
	el* l = malloc(sizeof(el));
	(*l).key = input;
	(*l).next = NULL;
	n--;
	el* testa = l;

	for(; n>0; n--)
	{
		scanf("%d", &input);
		el* new = malloc(sizeof(el));
		(*new).key = input;
		(*new).next = NULL;
		(*l).next = new;
		l = new;
	}

	scanf("%d", &input);
	int pos = Cerca(testa, input);
	printf("%d\n", pos);
	while(pos != -1)
	{
		testa = MTF(testa, pos);
		scanf("%d", &input);
		pos = Cerca(testa, input);
		printf("%d\n", pos);
	}

	return 0;
}
