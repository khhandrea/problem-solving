#include <iostream>
#include <stack>

struct HW {
    int h;
    int w;
};

int main() {
    int H, W, delta, water = 0;
    std::stack<HW> stack;
    HW pos, cur;

    std::cin >> H >> W;

    for (cur.w = 0; cur.w < W; cur.w++) {
        std::cin >> cur.h;
        while (!stack.empty() && cur.h >= stack.top().h) {
            pos = stack.top();
            stack.pop();

            if (!stack.empty()) {
                delta = (stack.top().h > cur.h ? cur.h : stack.top().h) - pos.h;
                delta *= cur.w - stack.top().w - 1;
                water += delta;
            }
        }
        stack.push(cur);
    }

    std::cout << water << '\n';

    return 0;
}
