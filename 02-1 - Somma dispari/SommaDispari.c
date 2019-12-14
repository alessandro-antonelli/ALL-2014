#include <stdio.h>

int OddSum(int n)
{
	if(n<=0) return 0;
	return 2*n-1 + OddSum(n-1);
}

int main()
{
	int n;
	scanf("%d", &n);
	
	int result = OddSum(n);
	printf("%d\n", result);
	
	return 0;
}
