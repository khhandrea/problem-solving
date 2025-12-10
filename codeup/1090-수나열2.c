#include<stdio.h>
#include<math.h>

int main()
{
	int a, r, n;
	scanf("%d %d %d", &a, &r, &n);
	long long result = (int)pow((float)r, (float)(n-1));
	result *= a;
	printf("%lld", result);
	
	return 0;
}
