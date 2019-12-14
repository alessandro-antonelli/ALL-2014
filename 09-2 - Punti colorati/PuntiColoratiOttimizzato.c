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

int OrdinaAscissa(const void* a, const void* b)
{
	return (*((punto*) a)).x - (*((punto*) b)).x;
}

//int OrdinaOrdinata(const void* a, const void* b)
//{
	//return (*((punto*) a)).y - (*((punto*) b)).y;
//}

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

int PrimaX(punto* punti, int len, int x1)
{
	int sx = 0;
	int dx = len-1;
	int trovato = 0;
	int centro = (sx+dx)/2;

	while(sx <= dx && !trovato)
	{
		centro = (sx+dx)/2; 
		if(punti[centro].x > x1) dx = centro-1;
		else if(punti[centro].x < x1) sx = centro+1;
		else trovato=1;
	}

	//Nel caso in cui l'el precedente è >= x1, retrocedo
	while(centro-1 >= 0 && punti[centro-1].x >= x1) centro--;

	//Nel caso in cui l'el è < x1, avanzo al primo punto con x >= x1
	while(centro+1 < len && punti[centro].x < x1) centro++;

	return centro;
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

	//qsort(punti, n, sizeof(punto), OrdinaOrdinata);
	qsort(punti, n, sizeof(punto), OrdinaAscissa);

	int indreg;
	for(indreg=0; indreg<m; indreg++) //per ogni regione
	{
		int distinti = 0;
		int* coloridist = malloc(n * sizeof(int));

		//scorro i punti a partire dal primo con x adeguata finché le x non escono fuori dalla regione
		int indpunto = PrimaX(punti, n, regioni[indreg].x1);
		while(indpunto >= 0 && indpunto < n && punti[indpunto].x <= regioni[indreg].x2)
		{
			//Se il punto ha anche la y a posto, cerco il colore in coloridist (intervallo 0 | distinti). Se non c'è lo aggiungo e incremento #colori distinti.
			if(punti[indpunto].x >= regioni[indreg].x1 && punti[indpunto].x <= regioni[indreg].x2 && punti[indpunto].y >= regioni[indreg].y1 && punti[indpunto].y <= regioni[indreg].y2){
			if(!CercaColore(coloridist, distinti, punti[indpunto].c))
			{
				coloridist[distinti] = punti[indpunto].c;
				distinti++;
			}}
			indpunto++;
		}

		printf("%d\n", distinti);
		free(coloridist);
	}

	return 0;
}
