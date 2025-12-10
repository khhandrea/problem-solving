#include<stdio.h>

int main()
{
	int go[20][20]={0,}, num, x, y, i, j;
	scanf("%d", &num);
	for(i=1; i<=num; i++)
	{
		scanf("%d %d", &x, &y);
		go[x][y] = 1;
	}
	for(i=1; i<=19; i++)
	{
		for(j=1; j<=19; j++)
		{
			printf("%d ", go[i][j]);
		}
		printf("\n");
	}
	return 0;
}
