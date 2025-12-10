#include<stdio.h>

int main()
{
	int go[20][20], num, x, y, i, j;
	for(i=1; i<=19; i++)
	{
		for(j=1; j<=19; j++)
		{
			scanf("%d", &go[i][j]);
		}
	}
	
	scanf("%d", &num);
	for(j=1; j<=num; j++)
	{
		scanf("%d %d", &x, &y);
		for(i=1; i<=19; i++)
		{
			go[x][i] = (go[x][i]==1?0:1);
		}
		for(i=1; i<=19; i++)
		{
			go[i][y] = (go[i][y]==1?0:1);
		}
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
