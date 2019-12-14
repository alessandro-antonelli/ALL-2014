#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* mystrcat1(char *s1, char *s2)
{
	int len1 = strlen(s1);
	int len2 = strlen(s2);

	char* concatenazione = malloc((len1+len2+1) * sizeof(char));
	int i;
	for(i=0; i<len1; i++) concatenazione[i] = s1[i];
	for(i=0; i<len2; i++) concatenazione[i+len1] = s2[i];
	concatenazione[len1+len2] = '\0';

	return concatenazione;
}

int main()
{
	int len1;
	scanf("%d", &len1);
	char* s1 = malloc((len1 + 1) * sizeof(char));
	scanf("%s", s1);

	int len2;
	scanf("%d", &len2);
	char* s2 = malloc((len2 + 1) * sizeof(char));
	scanf("%s", s2);

	char* concatenazione = mystrcat1(s1, s2);

	printf("%s\n", concatenazione);

	return 0;
}
