#include <stdio.h>
#include <stdlib.h>

typedef unsigned char QueueData;
typedef struct QueueNode {
    QueueData data;
    struct QueueNode *link;
} QueueNode;

typedef struct Queue {
    QueueNode *front;
    QueueNode *rear;
} Queue;

void init_queue(Queue *queue);
char is_empty(Queue *queue);
void enqueue(Queue *queue, QueueData data);
QueueData dequeue(Queue *queue);

int main(void)
{
	///// initialize /////
	char n, m;
	char **maze;
	short **maze_depth;
	short depth = 1;
	QueueData node;
	int a, b;
	char *input;
	char i, j;	
	
	Queue queue;
	init_queue(&queue);
	
	scanf("%d %d", &a, &b);
	n = (char)a;
	m = (char)b;
	
	maze = (char **)malloc(sizeof(char *) * n);
	for(i = 0; i < n; i++)
		maze[i] = (char *)malloc(sizeof(char) * m);
		
	maze_depth = (short **)malloc(sizeof(short *) * n);
	for(i = 0; i < n; i++)
		maze_depth[i] = (short *)calloc(m, sizeof(short));
	
	input = (char *)malloc(sizeof(char) * (m+1));
	input[m] = 0;
	
	for(i = 0; i < n; i++)
	{
		scanf("%s", input);
		for(j = 0; j < m; j++)
		{
			maze[i][j] = input[j] - '0';
		}
	}
	
	///// BFS /////
	i = j = 0;
	enqueue(&queue, m*i + j);
	maze_depth[i][j] = depth;
	
	while(1)
	{	
		node = dequeue(&queue);
		i = a = node / m;
		j = b = node % m;
		depth = maze_depth[i][j] + 1;
		
		while (1) // search 4 directions
		{
			if (i == a && j == b) j = b - 1;
			else if (j == b - 1) j = b + 1;
			else if (j == b + 1) { i = a - 1; j = b; }
			else if (i == a - 1) i = a + 1;
			else break;	
			if(i < 0 || j < 0 || i == n || j == m) continue;
			
			if(maze[i][j] == 1)
			{
				if(maze_depth[i][j] == 0)
				{
					enqueue(&queue, m*i + j);
					maze_depth[i][j] += depth;
				}
			}
			if (i == n-1 && j == m-1) break;
		}
		if (i == n-1 && j == m-1) break;
	}
	
	printf("%d\n", depth);
	
	for(i = 0; i < n; i++) free(maze[i]);
	free(maze);
	for(i = 0; i < n; i++) free(maze_depth[i]);
	free(maze_depth);
	free(input);
	
	return 0;
}

void init_queue(Queue *queue)
{
    queue->front = NULL;
    queue->rear = NULL;
}

char is_empty(Queue *queue)
{
    return (queue->front == NULL);
}

void enqueue(Queue *queue, QueueData data)
{
    QueueNode *temp = (QueueNode *)malloc(sizeof(QueueNode));
    temp->data = data;
    temp->link = NULL;
    if (is_empty(queue))
    {
        queue->front = temp;
        queue->rear = temp;
    }
    else
    {
        queue->rear->link = temp;
        queue->rear = temp;
    }
}

QueueData dequeue(Queue *queue)
{
    QueueNode *temp = queue->front;
    QueueData data = temp->data;
    queue->front = queue->front->link;
    if (queue->front == NULL)
        queue->rear = NULL;
    free(temp);
    return data;
}
