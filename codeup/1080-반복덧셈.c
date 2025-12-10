#include<stdio.h>

int main()
{
	int i=1, n, sum=0;
	scanf("%d", &n);
	while(1)
	{
		sum += i;
		if(sum >= n) break;
		i++;
	}
	printf("%d", i);
	return 0;
}
