#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct strfr
{
	char* str;
	int freq;
} StrFreq;

int Compare(const void* a, const void* b)
{
	StrFreq uno = *((StrFreq*) a);
	StrFreq due = *((StrFreq*) b);

	return due.freq - uno.freq;
}

int compare2(const void* a, const void* b)
{
	return strcmp((*((StrFreq*) a)).str, (*((StrFreq*) b)).str);
}

int Ricerca(StrFreq* a, char* input, int len)
{
	int i=0;
	int trovato=0;
	while(!trovato && i<len)
	{
		if(strcmp(a[i].str, input) == 0) trovato=1;
		else i++;
	}
	if(!trovato) i=-1;
	return i;
}

int main()
{
	int n;
	int k;
	scanf("%d", &n);                                                                                                         
	scanf("%d", &k);
	StrFreq* a = malloc(n * sizeof(StrFreq));

	int strTot = 0;
	int strDist = 0;
	for(; strTot<n; strTot++)
	{
		char* input = malloc(101 * sizeof(char));
		scanf("%s", input);
		int pos = Ricerca(a, input, strDist);

		if(pos != -1) { a[pos].freq++; free(input); }
		else	{
			a[strDist].str = input;
			a[strDist].freq = 1;
			strDist++;
			}
	}

	qsort(a, strDist, sizeof(StrFreq), Compare);
	qsort(a, k, sizeof(StrFreq), compare2);
	
	for(strTot=0; strTot<k; strTot++) printf("%s\n", a[strTot].str);

	return 0;
}
