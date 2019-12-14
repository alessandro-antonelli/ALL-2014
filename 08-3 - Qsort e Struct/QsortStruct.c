#include <stdio.h>
#include <stdlib.h>

typedef struct _point
{
	int x;
	int y;
} point;

int Compare(const void* a, const void* b)
{
	point uno = *((point*) a);
	point due = *((point*) b);
	
	if(uno.x != due.x) return uno.x - due.x;
	else return due.y - uno.y; //a parità di ascissa, si ordina per ordinata decrescente
}

int main()
{
	int len;
	scanf("%d", &len);
	point* a = malloc(len * sizeof(point));
	
	int i;
	for(i=0; i<len; i++) scanf("%d %d", &a[i].x, &a[i].y);

	qsort(a, len, sizeof(point), Compare);

	for(i=0; i<len; i++) printf("%d %d\n", a[i].x, a[i].y);

	return 0;
}
