#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;
    std::vector<std::pair<std::pair<int, int>, int>> xyh(N);  // N<=100
    for (int i = 0; i < N; ++i) {
        int x, y, h;
        std::cin >> x >> y >> h;
        xyh.at(i) = std::make_pair(std::make_pair(x, y), h);
    }
    std::sort(xyh.begin(), xyh.end(),
              [](const std::pair<std::pair<int, int>, int>& p1,
                 const std::pair<std::pair<int, int>, int>& p2) {
                  return p1.second < p2.second;
              });

    for (int Cx = 0; Cx <= 100; ++Cx) {
        for (int Cy = 0; Cy <= 100; ++Cy) {
            int x         = xyh.at(N - 1).first.first;
            int y         = xyh.at(N - 1).first.second;
            int h         = xyh.at(N - 1).second;           // h!=0
            int H         = h + abs(x - Cx) + abs(y - Cy);  // H <= 1e9+200
            bool isCenter = true;
            for (int i = 0; i < N - 1; ++i) {
                x = xyh.at(i).first.first;
                y = xyh.at(i).first.second;
                h = xyh.at(i).second;
                if (h != std::max(H - abs(x - Cx) - abs(y - Cy), 0)) {
                    isCenter = false;
                    break;
                }
            }
            if (isCenter) {
                std::cout << Cx << ' ' << Cy << ' ' << H << '\n';
                return 0;
            }
        }
    }

    return 1;
}