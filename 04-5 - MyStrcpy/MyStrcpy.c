#include <stdio.h>

char* mystrcpy(char* dest, char* src)
{
	int i = -1;
	char lastchar;
	do {
		i++;
		lastchar = src[i];
		dest[i] = lastchar;
	} while(lastchar != '\0');
	return dest;
}

int main()
{
	char s1[1001];
	char s2[1001];
	scanf("%s", s1);
	
	mystrcpy(s2, s1);

	printf("%s\n", s2);
	return 0;
}
