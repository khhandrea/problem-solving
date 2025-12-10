#include<stdio.h>

int main()
{
	char x;
	int i;
	scanf("%x", &x);
	for(i=1; i<=15; i++)
	{
		printf("%X*%X=%X\n", x, i, x*i);
	}
	return 0;
}
