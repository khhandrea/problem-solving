#include<stdio.h>

int main()
{
	int i, n, sum;
	scanf("%d", &n);
	for(i=1; sum<n; sum+=i, i++){}
	printf("%d", i-1);
	return 0;
}
