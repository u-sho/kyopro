#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

template <typename T>
std::istream &operator>>(std::istream &is, std::vector<T> &v) {
    for (T &in : v) is >> in;
    return is;
}
int main(void) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);  // rate
    std::cin >> a;
    /**
     * [0]~399 : gray
     * [1]~799 : brown
     * [2]~1199: green
     * [3]~1599: water
     * [4]~1999: blue
     * [5]~2399: yellow
     * [6]~2799: orange
     * [7]~3199: red
     * [8]       free
     */
    std::vector<int> r(9);
    std::fill(r.begin(), r.end(), 0);
    for (int ae : a) {
        int ri = std::min(ae / 400, 8);
        r.at(ri)++;
    }

    int ans_min = 0;
    for (int i = 0; i < 8; ++i) {
        if (r.at(i) > 0) ++ans_min;
    }
    int ans_max = ans_min + r.at(8);

    ans_min = std::max(1, ans_min);

    std::cout << ans_min << ' ' << ans_max << '\n';

    return 0;
}
