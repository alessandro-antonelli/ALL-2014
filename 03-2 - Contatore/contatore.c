#include <stdio.h>

void reset(int array[], int len)
{
	int i;
	for(i=0; i<len; i++) array[i] = 0;
}

void add(int array[], int len, int val)
{
	if(val >= 0 && val < len) array[val]++;
}

int main()
{
	int freq[10];
	reset(freq, 10);

	int LastInput = -2;
	while(LastInput != -1)
	{
		scanf("%d", &LastInput);
		add(freq, 10, LastInput);
	}

	int i;
	for(i=0; i<10; i++) printf("%d\n", freq[i]);

	return 0;
}
