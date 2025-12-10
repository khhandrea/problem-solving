#include <stdio.h>
#include <vector>

using namespace std;

int main() {
    unsigned long min, max;
    unsigned int i, j, size, count = 0;
    vector<bool>::iterator iter;

    scanf("%ld %ld", &min, &max);
    size = max - min + 1;
    vector<bool> sieve(size, true);

    // 2^2, 3^3, 4^4, ...
    for (i=2; i*i<=max; i++) {
        for (j=0; (min+j)%(i*i)!=0; j++);
        for (; (min+j)<=max; j+=i*i) {
            sieve[j] = false;
        }
    }

    for (iter=sieve.begin(); iter!=sieve.end(); iter++)
        if (*iter)
            count++;

    printf("%d\n", count);

    return 0;
}