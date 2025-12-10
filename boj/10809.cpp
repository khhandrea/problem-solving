#include <stdio.h>

int main()
{
    char S[101];
    short result['z' - 'a' + 1];
    short i;
    scanf("%s", S);

    for (i=0; i<='z' - 'a'; i++) {
        result[i] = -1;
    }

    for (i=0; S[i]!=0; i++) {
        if (result[S[i] - 'a'] == -1) {
            result[S[i] - 'a'] = i;
        }
    }

    for (i=0; i<='z' - 'a'; i++) {
        printf("%hd ", result[i]);
    }

    return 0;
}