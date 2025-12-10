#include <stdio.h>

int main(void)
{
    short sugar[2] = {5, 3};
    short remain;
    short count = 0;
    
    scanf("%hd", &remain);
    
    for(; (remain % 5) != 0 && remain >= 3; remain-=3, count++);
    if((remain % 5) == 0) 
    {
        count += remain / 5;
        printf("%d", count);
    }
    else
    {
        printf("-1");
    }
    
    return 0;
}