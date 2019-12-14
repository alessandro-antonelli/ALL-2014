#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _gruppo
{
	char* principale;
	char** stringhe;
	int nStringhe;
} gruppo;

int OrdinaCaratteri(const void* a, const void* b)
{
	char uno[2];
	char due[2];
	uno[0] = *((char*) a);
	due[0] = *((char*) b);
	uno[1] = '\0'; due[1] = '\0';

	return strcmp(uno, due);
}

int OrdinaStringhe(const void* a, const void* b)
{
	char* uno = *((char**) a);
	char* due = *((char**) b);
	return strcmp(uno, due);
}

int OrdinaGruppi(const void* a, const void* b)
{
	gruppo uno = *((gruppo*) a);
	gruppo due = *((gruppo*) b);
	return strcmp(uno.principale, due.principale);
}

char* AnagrammaPrincipale(char* stringa)
{
	int len = strlen(stringa);
	char* principale = malloc((len+1) * sizeof(char));
	strncpy(principale, stringa, len+1);
	qsort(principale, len, sizeof(char), OrdinaCaratteri);
	return principale;
}

int CercaGruppo(gruppo* gruppi, int nGruppi, char* principale)
{
	int trovato=0;
	int i=0;
	while(i<nGruppi && !trovato)
	{
		if(strcmp(gruppi[i].principale, principale) == 0) trovato=1;
		else i++;
	}
	if(!trovato) i=-1;
	return i;
}

int main()
{
	int n; //n numero totale di stringhe
	scanf("%d", &n);
	gruppo* gruppi = malloc(n * sizeof(gruppo));
	int nGruppi = 0;

	//Leggo e memorizzo le stringhe
	int i;
	for(i=0; i<n; i++)
	{
		char* stringa = malloc(20 * sizeof(char));
		scanf("%s", stringa);

		char* principale = AnagrammaPrincipale(stringa);
		int iGruppo = CercaGruppo(gruppi, nGruppi, principale);
		if(iGruppo != -1)
		{
			//Esiste già un gruppo con quell'anagramma principale
			free(principale);
			int indiceInserimento = gruppi[iGruppo].nStringhe;
			gruppi[iGruppo].stringhe[indiceInserimento] = stringa;
			gruppi[iGruppo].nStringhe++;
		}
		else
		{
			//Non esiste ancora un gruppo con quell'anagramma principale
			gruppi[nGruppi].principale = principale;
			gruppi[nGruppi].nStringhe = 1;
			gruppi[nGruppi].stringhe = malloc(n * sizeof(char*));
			gruppi[nGruppi].stringhe[0] = stringa;
			nGruppi++;
		}
	}

	//Ordino array dei gruppi
	qsort(gruppi, nGruppi, sizeof(gruppo), OrdinaGruppi);

	//Ordino le stringhe di ogni gruppo, stampo e dealloco
	for(i=0; i<nGruppi; i++)
	{
		free(gruppi[i].principale);
		qsort(gruppi[i].stringhe, gruppi[i].nStringhe, sizeof(char*), OrdinaStringhe);
		int j;
		for(j=0; j < gruppi[i].nStringhe; j++)
		{
			printf("%s", gruppi[i].stringhe[j]);
			if(j+1 < gruppi[i].nStringhe) printf(" ");
			free(gruppi[i].stringhe[j]);
		}
		free(gruppi[i].stringhe);
		if(i+1 < nGruppi) printf("\n");
	}
	free(gruppi);

	return 0;
}
