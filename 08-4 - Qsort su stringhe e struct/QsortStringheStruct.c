#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct strin
{
	char* str;
	int len;
} SuperStringa;

int Compare(const void* a, const void* b)
{
	SuperStringa uno = *((SuperStringa*) a);
	SuperStringa due = *((SuperStringa*) b);
	
	if(uno.len != due.len) return uno.len - due.len;
	else return strcmp(uno.str, due.str);
}

int main()
{
	int len;
	scanf("%d", &len);
	SuperStringa* a = malloc(len * sizeof(SuperStringa));
	
	int i;
	for(i=0; i<len; i++)
	{
		a[i].str = malloc(101 * sizeof(char));
		scanf("%s", a[i].str);
		a[i].len = strlen(a[i].str);
	}

	qsort(a, len, sizeof(SuperStringa), Compare);

	for(i=0; i<len; i++)
	{
		printf("%s\n", a[i].str);
		free(a[i].str);
	}
	free(a);

	return 0;
}
