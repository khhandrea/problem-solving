#include <iostream>
#include <stack>

struct HI {
    int h;
    int i;
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    long long area, max_area;
    HI top, cur;
    std::stack<HI> stack;

    while (true) {
        std::cin >> n;

        if (n == 0) {
            break;
        }

        max_area = 0;

        for (cur.i = 0; cur.i < n; cur.i++) {
            std::cin >> cur.h;

            while (!stack.empty() && cur.h < stack.top().h) {
                top = stack.top();
                stack.pop();

                area = top.h;
                area *= cur.i - (stack.empty() ? 0 : stack.top().i + 1);
                max_area = (area > max_area ? area : max_area);
            }

            stack.push(cur);
        }

        while (!stack.empty()) {
            top = stack.top();
            stack.pop();

            area = top.h;
            area *= (stack.empty() ? n : n - stack.top().i - 1);
            max_area = (area > max_area ? area : max_area);
        }

        std::cout << max_area << '\n';
    }

    return 0;
}
