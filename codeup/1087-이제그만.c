#include<stdio.h>

int main()
{
	int i, n, sum=0;
	scanf("%d", &n);
	for(i=1; sum<n ; sum+=i, i++){}
	printf("%d", sum);
	
	return 0;
}
