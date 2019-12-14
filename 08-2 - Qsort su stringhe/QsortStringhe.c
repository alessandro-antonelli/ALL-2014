#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Compare(const void* a, const void* b)
{
	char* s1 = *((char**) a);
	char* s2 = *((char**) b);
	
	return (-1) * (strcmp(s1, s2));
}

int main()
{
	int len;
	scanf("%d", &len);
	char** a = malloc(len * sizeof(char*));
	
	int i;
	for(i=0; i<len; i++)
	{
		a[i] = malloc(101 * sizeof(char));
		scanf("%s", a[i]);
	}

	qsort(a, len, sizeof(char*), Compare);

	for(i=0; i<len; i++)
	{
		printf("%s\n", a[i]);
		free(a[i]);
	}
	free(a);

	return 0;
}
