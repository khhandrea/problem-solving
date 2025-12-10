#include <stdio.h>

int main(void)
{
    unsigned int S;
    int N = 0, i = 0;
    scanf("%d", &S);
    do
    {
        N += 1;
        S -= ++i;
    } while(S >= i+1);
    printf("%d", N);
    return 0;
}