#include <iostream>

int main() {
    int W, H, N;
    std::cin >> W >> H >> N;
    int x1 = 0, x2 = W, y3 = 0, y4 = H;
    for (int i = 0; i < N; i++) {
        int x, y, a;
        std::cin >> x >> y >> a;
        if (a == 1) x1 = std::max(x1, x);
        if (a == 2) x2 = std::min(x2, x);
        if (a == 3) y3 = std::max(y3, y);
        if (a == 4) y4 = std::min(y4, y);
    }

    if (x2 < x1 || y4 < y3)
        std::cout << "0\n";
    else
        std::cout << (x2 - x1) * (y4 - y3) << "\n";

    return 0;
}
