#include<stdio.h>

int main()
{
	int h, w, n, l, d, x, y, i, j, k;
	scanf("%d %d %d", &h, &w, &n);
	int ground[101][101]={0,};
	
	for(k=1; k<=n; k++)
	{
		scanf("%d %d %d %d", &l, &d, &x, &y);
		for(i=1; i<=l; i++)
		{
			if(d==1)
			{
				ground[x+i-1][y] = 1;
			}
			else
			{
				ground[x][y+i-1] = 1;
			}
		}
	}
	
	for(i=1; i<=h; i++)
	{
		for(j=1; j<=w; j++)
		{
			printf("%d ", ground[i][j]);
		}
		printf("\n");
	}
	return 0;
}
