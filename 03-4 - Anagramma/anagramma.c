#include <stdio.h>

void reset(int a[], int len)
{
	int i;
	for(i=0; i<len; i++) a[i] = 0;
}

int anagramma(unsigned char *s1, unsigned char *s2)
{
	//Inserisce le frequenze di s1
	int freq1[256];
	reset(freq1, 256);

	int i = 0;
	char lastchar = s1[0];
	while(lastchar)
	{
		freq1[lastchar]++;
		i++;
		lastchar = s1[i];
	}

	//Inserisce le frequenze di s2
	int freq2[256];
	reset(freq2, 256);

	i = 0;
	lastchar = s2[0];
	while(lastchar)
	{
		freq2[lastchar]++;
		i++;
		lastchar = s2[i];
	}

	//Confronta le due frequenze
	i = 0;
	int diverse = 0;
	while(i<256 && diverse == 0)
	{
		if(freq1[i] != freq2[i]) diverse = 1;
		i++;
	}
	
	return !diverse;
}

int main()
{
	unsigned char s1[1001];
	unsigned char s2[1001];
	scanf("%s", s1);
	scanf("%s", s2);

	int result = anagramma(s1, s2);
	printf("%d\n", result);

	return 0;
}
