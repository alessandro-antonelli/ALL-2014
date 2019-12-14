#include <stdio.h>

int mystrlen(char *s)
{
	int len = 0;
	char lastchar = s[0];
	while(lastchar)
	{
		len++;
		lastchar = s[len];
	}
	return len;
}

int main()
{
	char s[1001];
	scanf("%s", s);

	int len = mystrlen(s);
	printf("%d\n", len);
	
	return 0;
}
