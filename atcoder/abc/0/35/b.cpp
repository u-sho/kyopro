#include <algorithm>  // min/max
#include <cassert>
#include <cstdlib>  // abs(int)
#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::string;
using std::vector;

using XY = std::pair<int, int>;
using std::make_pair;

enum Orders {
    L = 0,
    R = 1,
    U = 2,
    D = 3,
};
vector<XY> ORDERS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
XY operator+(const XY &xy1, const XY &xy2) {
    return make_pair(xy1.first + xy2.first, xy1.second + xy2.second);
}

enum Ts {
    MAX = 1,
    MIN = 2,
};
std::istream &operator>>(std::istream &is, Ts &t) {
    short tin;
    is >> tin;
    assert((tin == Ts::MAX || tin == Ts::MIN));
    if (tin == Ts::MAX) t = Ts::MAX;
    if (tin == Ts::MIN) t = Ts::MIN;

    return is;
}

int main() {
    constexpr XY Takahashi = make_pair(0, 0);
    XY drone               = make_pair(0, 0);

    string S;
    cin >> S;  // |S|<=1e5
    Ts T;
    cin >> T;  // 1|2

    int question_count = 0;
    for (const char Si : S) {
        if (Si == '?') question_count++;

        if (Si == 'L') drone = drone + ORDERS.at(Orders::L);
        if (Si == 'R') drone = drone + ORDERS.at(Orders::R);
        if (Si == 'U') drone = drone + ORDERS.at(Orders::U);
        if (Si == 'D') drone = drone + ORDERS.at(Orders::D);

        // cout << Si << ':' << drone.first << ' ' << drone.second << '\n';
    }

    int xd   = abs(Takahashi.first - drone.first);
    int yd   = abs(Takahashi.second - drone.second);
    int dist = xd + yd;

    if (T == Ts::MAX) {
        cout << dist + question_count << '\n';
    }
    if (T == Ts::MIN) {
        if (dist >= question_count)
            cout << dist - question_count << '\n';
        else {
            cout << (question_count - dist) % 2 << '\n';
        }
    }
    return 0;
}