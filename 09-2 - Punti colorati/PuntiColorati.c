#include <stdio.h>
#include <stdlib.h>

typedef struct _punto
{
	int x;
	int y;
	int c;
} punto;

typedef struct _regione
{
	int x1;
	int y1;
	int x2;
	int y2;
} regione;

int CercaColore(int* coloridist, int len, int colore)
{
	int i = 0;
	int trovato = 0;
	while(!trovato && i<len)
	{
		if(coloridist[i] == colore) trovato = 1;
		i++;
	}
	return trovato;
}

int main()
{
	int n, m; //n punti ed m interrogazioni
	scanf("%d %d", &n, &m);
	punto* punti = malloc(n * sizeof(punto));
	regione* regioni = malloc(m * sizeof(regione));

	int i;
	for(i=0; i<n; i++) scanf("%d %d %d", &punti[i].x, &punti[i].y, &punti[i].c);
	for(i=0; i<m; i++) scanf("%d %d %d %d", &regioni[i].x1, &regioni[i].y1, &regioni[i].x2, &regioni[i].y2);

	int indreg;
	for(indreg=0; indreg<m; indreg++) //per ogni regione
	{
		int distinti = 0;
		int* coloridist = malloc(n * sizeof(int));

		//scorro i punti
		int indpunto;
		for(indpunto = 0; indpunto < n; indpunto++)
		{
			//Se il punto è compreso nella regione, cerco il colore in coloridist (intervallo 0 | distinti). Se non c'è lo aggiungo e incremento #colori distinti.
			if(punti[indpunto].x >= regioni[indreg].x1 && punti[indpunto].x <= regioni[indreg].x2 && punti[indpunto].y >= regioni[indreg].y1 && punti[indpunto].y <= regioni[indreg].y2)
			if(!CercaColore(coloridist, distinti, punti[indpunto].c))
			{
				coloridist[distinti] = punti[indpunto].c;
				distinti++;
			}
		}

		printf("%d\n", distinti);
		free(coloridist);
	}

	return 0;
}
