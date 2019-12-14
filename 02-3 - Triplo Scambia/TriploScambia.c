#include <stdio.h>

void tswap(int *x, int *y, int *z)
{
	int temp = *x;
	*x = *z;
	*z = *y;
	*y = temp;
}

int main()
{
	int a, b, c;
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);

	tswap(&a, &b, &c);

	printf("%d\n", a);
	printf("%d\n", b);
	printf("%d\n", c);
	return 0;
}
