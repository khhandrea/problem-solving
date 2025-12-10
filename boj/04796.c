#include <stdio.h>

int main(void)
{
    int L, P, V, i = 1;
    int result;
    while(1)
    {
        scanf("%d %d %d", &L, &P, &V);
        if((L == 0) && (P == 0) && (V == 0)) break;
        if((V % P) < L) result = (L * (V / P)) + (V % P);
        else result = (L * (V / P)) + L;
        printf("Case %d: %d\n", i++, result);
    }
    
    return 0;
}