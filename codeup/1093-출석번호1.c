#include<stdio.h>

int main()
{
	int i, num, n, result[23] = {0,};
	scanf("%d", &num);
	for(i=0; i<num; i++) 
	{
		scanf("%d", &n);
		result[n-1] += 1;
	}
	
	for(i=0; i<23; i++)
	{
		printf("%d ", result[i]);
	}
	return 0;
}
