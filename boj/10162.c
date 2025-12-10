#include<stdio.h>
#define asec 300
#define bsec 60
#define csec 10

int main(void)
{
    int t;
    int a=0, b=0, c=0;
    scanf("%d", &t);

    while(t>0)
    {
        if(t>=asec)
        {
            t -= asec;
            a += 1;
        }
        else if(t>=bsec)
        {
            t -= bsec;
            b += 1;
        }
        else if(t>=csec)
        {
            t -= csec;
            c += 1;
        }
        else
        {
            printf("-1");
            return 0;
        }
        
    }

    printf("%d %d %d", a, b, c);
    return 0;
}