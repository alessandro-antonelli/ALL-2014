#include <stdio.h>
#include <stdlib.h>

typedef struct _el
{
	int key;
	int ricerche;
	struct _el* next;
	struct _el* prev;
} el;

int Ricerca(el* l, int cercato)
{
	int risultato = -1;
	int posizione = 0;
	while(risultato == -1 && l != NULL)
	{
		if((*l).key == cercato)
		{
			risultato = posizione;
			(*l).ricerche++;
		}
		l = (*l).next;
		posizione++;
	}
	return risultato;
}

el* Aggiusta(el* l, int pos)
{
	if(pos != -1)
	{
		int i;
		el* incasinatore = l;
		for(i=0; i<pos; i++) incasinatore = (*incasinatore).next;
		el* pre = (*incasinatore).prev;
	
		while(pre != NULL && (*incasinatore).ricerche > (*pre).ricerche)
		{
			if((*incasinatore).next != NULL) (*(*incasinatore).next).prev = pre;
			if((*pre).prev != NULL) (*(*pre).prev).next = incasinatore;
			(*pre).next = (*incasinatore).next;
			(*incasinatore).next = pre;
			(*incasinatore).prev = (*pre).prev;
			(*pre).prev = incasinatore;
			pre = (*incasinatore).prev;
		}
	
		if(pre == NULL) l = incasinatore;
	}
	return l;
}

int main()
{
	int n;
	scanf("%d", &n);

	//Crea la lista
	int input;
	scanf("%d", &input);

	el* testa = malloc(sizeof(el));
	(*testa).ricerche = 0;
	(*testa).key = input;
	(*testa).prev = NULL;
	(*testa).next = NULL;
	n--;

	//Accoda in lista
	el* l = testa;
	for(; n>0; n--)
	{
		scanf("%d", &input);
		el* new = malloc(sizeof(el));
		(*new).ricerche = 0;
		(*new).key = input;
		(*new).prev = l;
		(*new).next = NULL;
		(*l).next = new;
		l = new;
	}

	//Ricerche
	scanf("%d", &input);
	int pos = Ricerca(testa, input);
	printf("%d\n", pos);
	testa = Aggiusta(testa, pos);
	while(pos != -1)
	{
		scanf("%d", &input);
		pos = Ricerca(testa, input);
		printf("%d\n", pos);
		testa = Aggiusta(testa, pos);
	}

	return 0;
}
