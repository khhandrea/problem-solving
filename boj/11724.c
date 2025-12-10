#include <stdio.h>
#include <stdlib.h>

void DFS(char **mat, short n, short v, char *visited);

int main(void)
{
	// Initialize
	short n, m;
	short i;
	short a, b;
	short count = 0;
	
	char *visited;
	char **mat;
	
	scanf("%hd %hd", &n, &m);
	
	visited = (char *)calloc(n, sizeof(char));
	
	mat = (char **)malloc(sizeof(char *) * n);
	for(i = 0; i < n; i++)
		mat[i] = (char *)calloc(n, sizeof(char));
    
	for(i = 0; i < m; i++)
	{
		scanf("%hd %hd", &a, &b);
		mat[a-1][b-1] = mat[b-1][a-1] = 1;
	}
	
	
	// DFS
	i = 0;
	while(1)
	{
		for(; i < n; i++)
			if(!visited[i])
				break;
		if(i==n) break;
		DFS(mat, n, i, visited);
		count += 1;
	}
	
	printf("%d", count);
	
	// freeing
	for(i = 0; i < n; i++)
		free(mat[i]);
	free(mat);
		
	return 0;
}

void DFS(char **mat, short n, short v, char *visited)
{
	short i;
	visited[v] = 1;
	for(i = 0; i < n; i++)
		if(mat[v][i])
			if(!visited[i])
				DFS(mat, n, i, visited);
}
