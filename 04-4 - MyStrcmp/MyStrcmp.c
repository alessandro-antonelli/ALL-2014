#include <stdio.h>
#include <string.h>

int mystrcmp(char* s1, char* s2)
{
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	int result = 0;
	int cifra = 0;
	while(result == 0 && cifra<len1 && cifra<len2)
	{
		if(s1[cifra] < s2[cifra]) result = -1;
		else if(s1[cifra] > s2[cifra]) result = 1;
		cifra++;
	}
	return result;
}

int main()
{
	char s1[1001];
	char s2[1001];
	scanf("%s", s1);
	scanf("%s", s2);

	int confronto = mystrcmp(s1, s2);

	if(confronto <= 0) printf("%d\n", confronto);
	else printf("+%d\n", confronto);

	return 0;
}
