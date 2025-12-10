#include<stdio.h>

int main()
{
	int i, num, n, min=24;
	scanf("%d", &num);
	for(i=1; i<=num; i++)
	{
		scanf("%d", &n);
		min = (n<min?n:min);
	 } 
	printf("%d", min);
	return 0;
}
