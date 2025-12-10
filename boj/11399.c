#include <stdio.h>
#include <stdlib.h> 

int compare(const void *a, const void *b) 
{
    int num1 = *(short *)a;
    int num2 = *(short *)b;

    if (num1 < num2) 
        return -1; 
    
    if (num1 > num2) 
        return 1;
    
    return 0;
}

int main(void)
{
    short N;
    short* P;
    short i, j;
    int result = 0;

    scanf("%hd", &N);
    P = (short*)malloc(sizeof(short)*N);
    for(i=0; i<N; i++) scanf("%hd", &P[i]);
    qsort(P, N, sizeof(short), compare);
    for(i=0; i<N; i++)
        for(j=0; j<=i; j++)
            result += P[j];
    printf("%d", result);
    free(P);
    
    return 0;
}