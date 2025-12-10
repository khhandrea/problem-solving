#include <stdio.h>

int main(void)
{
    short change[6] = {500, 100, 50, 10, 5, 1};
    char i = 0;
    short price;
    short remain;
    short count = 0;
    
    scanf("%hd", &price);
    remain = 1000 - price;
    
    do {
        if(remain >= change[i])
        {
            remain -= change[i];
            count += 1;
        }
        else 
        {
            i += 1;
        }
    } while(remain > 0);

    printf("%d", count);
    return 0;
}