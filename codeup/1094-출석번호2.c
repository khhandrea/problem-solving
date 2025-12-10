#include<stdio.h>

int main()
{
	int i, num, n[10000];
	scanf("%d", &num);
	for(i=0; i<num; i++)
	{
		scanf("%d", &n[i]);
	}
	for(i=num-1; i>=0; i--)
	{
		printf("%d ", n[i]);
	} 
	return 0;
}
