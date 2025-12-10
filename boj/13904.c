#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    short N;
    short **HW;
    short i, j;
    short day = 0;
    short *clear_day;
    short score;
    int total_score = 0;
    scanf("%hd", &N);
    HW = (short**)malloc(sizeof(short*)*N);
    for(i=0; i<N; i++) 
    {
        HW[i] = (short*)malloc(sizeof(short)*2);
        scanf("%hd %hd", &HW[i][0], &HW[i][1]);
        day = (day > HW[i][0]) ? day : HW[i][0];
    }

    for(i=day; i>0; i--)
    {
        score = 0;
        for(j=0; j<N; j++)
            if(i <= HW[j][0])
                if(score < HW[j][1])
                {
                    score = HW[j][1];
                    clear_day = &HW[j][0];
                }
        total_score += score;
        *clear_day = 0;
    }

    printf("%d", total_score);

    for(i=0; i<N; i++) free(HW[i]);
    free(HW);

    return 0;
}