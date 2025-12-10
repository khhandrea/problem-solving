// 2108번 통계학
#include <stdio.h>
#include <math.h>
#include <set>
#include <map>

using namespace std;

int main() {
    int N, i;
    double sum = 0;
    short number, medium, min, max;
    short most = 0, argmost = 0;
    bool is_second = false;
    multiset<short> numbers;
    multiset<short>::iterator n_iter;
    map<short, int> dict;
    map<short, int>::iterator d_iter;


    scanf("%d", &N);
    for (i=0; i<N; i++) {
        scanf("%hd", &number);
        numbers.insert(number);
        sum += number;
        dict[number] += 1;
    }


    // Medium and max
    i = 0;
    for (n_iter=numbers.begin(); n_iter!=numbers.end(); n_iter++) {
        if (i == (N - 1) / 2) {
            medium = *n_iter;
        }
        if (i == N - 1) {
            max = *n_iter;
        }
        i += 1;
    }

    // Most
    for (d_iter=dict.begin(); d_iter!=dict.end(); d_iter++) {
        if (d_iter->second > most) {
            argmost = d_iter->first;
            most = d_iter->second;
            is_second = false;
        }
        else if (d_iter->second == most && !is_second) {
            argmost = d_iter->first;
            most = d_iter->second;
            is_second = true;
        }
    }

    // Range
    min = *numbers.begin();

    printf("%d\n", (int)floor((sum / N) + 0.5));
    printf("%d\n", medium);
    printf("%d\n", argmost);
    printf("%d\n", max - min);

    return 0;
}