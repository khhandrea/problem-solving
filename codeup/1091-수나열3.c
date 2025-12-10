#include<stdio.h>

int main()
{
	int a, m, d, n, i;
	scanf("%d %d %d %d", &a, &m, &d, &n);
	long long result = a;
	for(i=1; i<=n-1; result=result*m+d,i++){}
	printf("%lld", result);
	return 0;
}
