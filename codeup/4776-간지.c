#include<stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	printf("%c%d",(n+8)%12+65, (n+6)%10);
	return 0;
}
