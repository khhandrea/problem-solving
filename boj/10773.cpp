// 10773번 제로
#include <stdio.h>
#include <stack>

int main() {
    int K, item, i;
    unsigned result = 0;
    std::stack<int> s;

    scanf("%d", &K);
    for (i=0; i<K; i++) {
        scanf("%d", &item);
        if (item != 0) {
            s.push(item);
        }
        else {
            s.pop();
        }
    }

    while (!s.empty()) {
        result += s.top();
        s.pop();
    }
    printf("%u\n", result);

    return 0;
}