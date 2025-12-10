#include <iostream>

int main() {
    int H, W, total = 0;
    int *heights, *lmax, *rmax;

    std::cin >> H >> W;
    heights = new int[W];
    lmax = new int[W];
    rmax = new int[W];

    for (int w = 0; w < W; w++) {
        std::cin >> heights[w];
    }

    lmax[0] = heights[0];
    rmax[W - 1] = heights[W - 1];
    for (int w = 1; w < W; w++) {
        lmax[w] = (lmax[w - 1] > heights[w] ? lmax[w - 1] : heights[w]);
        rmax[W - w - 1] = (rmax[W - w] > heights[W - w - 1] ? rmax[W - w] : heights[W - w - 1]);
    }

    for (int w = 0; w < W; w++) {
        total += (lmax[w] > rmax[w] ? rmax[w] : lmax[w]) - heights[w];
    }
    std::cout << total << '\n';

    return 0;
}
