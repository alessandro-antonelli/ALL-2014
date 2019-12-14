#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _squadra
{
	char* nome;
	int punteggio;
	int segnati;
	int subiti;
} squadra;

int OrdinAlfabetico(const void* a, const void* b)
{
	squadra uno = (*(* (squadra**) a));
	squadra due = (*(* (squadra**) b));
	return strcmp(uno.nome, due.nome);
}

int OrdinaGolSegnati(const void* a, const void* b)
{
	squadra uno = (*(* (squadra**) a));
	squadra due = (*(* (squadra**) b));
	return due.segnati - uno.segnati;
}

int OrdinaDiffReti(const void* a, const void* b)
{
	squadra uno = (*(* (squadra**) a));
	squadra due = (*(* (squadra**) b));

	int diffA = uno.segnati - uno.subiti;
	int diffB = due.segnati - due.subiti;

	return diffB - diffA;
}

int OrdinaPunteggio(const void* a, const void* b)
{
	squadra uno = (*(* (squadra**) a));
	squadra due = (*(* (squadra**) b));
	return due.punteggio - uno.punteggio;
}

int TrovaIndice(squadra** squadre, int len, char* nome)
{
	int i = 0;
	int trovato = -1;
	while(trovato == -1 && i<len)
	{
		if(strcmp((*squadre[i]).nome, nome) == 0) trovato = i;
		i++;
	}
	return trovato;
}

int CreaSquadra(squadra** squadre, int len, char* nome)
{
	squadre[len] = malloc(sizeof(squadra));
	(*squadre[len]).nome = nome;
	(*squadre[len]).punteggio = 0;
	(*squadre[len]).segnati = 0;
	(*squadre[len]).subiti = 0;
	return len;
}

void StampaClassifica(squadra** squadre, int len)
{
	int i;
	for(i=0; i<len; i++)
	{
		printf("%s\n", (*squadre[i]).nome);
		free((*squadre[i]).nome);
		free(squadre[i]);
	}
}

int main()
{
	int nPartite;
	int nSquadre = 0;
	scanf("%d", &nPartite);

	squadra** squadre = malloc(2 * nPartite * sizeof(squadra*));

	for(; nPartite > 0; nPartite--)
	{
		//LEGGE IL RISULTATO DELLA PARTITA
		char* nomeA = malloc(101 * sizeof(char));
		char* nomeB = malloc(101 * sizeof(char));
		int golA, golB;
		scanf("%s", nomeA);
		scanf("%d", &golA);
		scanf("%s", nomeB);
		scanf("%d", &golB);

		//TROVA LE DUE SQUADRE NELL'ARRAY o se non ci sono LE CREA
		int indA, indB;
		indA = TrovaIndice(squadre, nSquadre, nomeA);
		indB = TrovaIndice(squadre, nSquadre, nomeB);
		if(indA == -1) { indA = CreaSquadra(squadre, nSquadre, nomeA); nSquadre++; }
		else free(nomeA);
		if(indB == -1) { indB = CreaSquadra(squadre, nSquadre, nomeB); nSquadre++; }
		else free(nomeB);

		//ASSEGNA IL PUNTEGGIO
		if(golA > golB) //A vince
			(*squadre[indA]).punteggio = (*squadre[indA]).punteggio + 3;
		else
		{
			if(golB > golA) //B vince
				(*squadre[indB]).punteggio = (*squadre[indB]).punteggio + 3;
			else //pareggio
			{
				(*squadre[indA]).punteggio = (*squadre[indA]).punteggio + 1;
				(*squadre[indB]).punteggio = (*squadre[indB]).punteggio + 1;
			}
		}

		//AGGIUNGE GOL SEGNATI E SUBITI
		(*squadre[indA]).segnati = (*squadre[indA]).segnati + golA;
		(*squadre[indB]).segnati = (*squadre[indB]).segnati + golB;
		(*squadre[indA]).subiti = (*squadre[indA]).subiti + golB;
		(*squadre[indB]).subiti = (*squadre[indB]).subiti + golA;
	}

	//ORDINA
	qsort(squadre, nSquadre, sizeof(squadra*), OrdinAlfabetico);
	qsort(squadre, nSquadre, sizeof(squadra*), OrdinaGolSegnati);
	qsort(squadre, nSquadre, sizeof(squadra*), OrdinaDiffReti);
	qsort(squadre, nSquadre, sizeof(squadra*), OrdinaPunteggio);

	//STAMPA E DEALLOCA
	StampaClassifica(squadre, nSquadre);
	free(squadre);

	return 0;
}
