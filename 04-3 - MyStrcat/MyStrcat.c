#include <stdio.h>
#include <string.h>

char* mystrcat(char *s1, char *s2)
{
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	
	int i;
	for(i=0; i<len2; i++) s1[len1+i] = s2[i];
	s1[len1+len2] = '\0';

	return s1;
}

int main()
{
	char s1[1001];
	char s2[1001];
	
	scanf("%s", s1);
	scanf("%s", s2);

	if(strlen(s1) + strlen(s2) < 1001) mystrcat(s1, s2);
	
	printf("%s\n", s1);

	return 0;
}
