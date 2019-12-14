#include <stdio.h>
#include <stdlib.h>

int main()
{
	int lena, i, j;
	scanf("%d", &lena);
	int* a = malloc(lena * sizeof(int));
	for(i=0; i<lena; i++) scanf("%d", &a[i]);

	int lenb;
	scanf("%d", &lenb);
	int* b = malloc(lenb * sizeof(int));
	for(i=0; i<lenb; i++) scanf("%d", &b[i]);
	
	int* c = malloc((lena+lenb) * sizeof(int));
	i=0; j=0;
	while(i<lena && j<lenb)
	{
		if(a[i] < b[j]) { c[i+j] = a[i]; i++; }
		if(b[j] < a[i]) { c[i+j] = b[j]; j++; }
	}
	while(i<lena) { c[i+j] = a[i]; i++; }
	while(j<lenb) { c[i+j] = b[j]; j++; }
	free(a); free(b);

	for(i=0; i<(lena+lenb); i++) printf("%d\n", c[i]);
	free(c);

	return 0;
}
