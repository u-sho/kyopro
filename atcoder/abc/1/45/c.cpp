#include <bits/stdc++.h>
using namespace std;

double distance(const pair<int, int>& xy1, const pair<int, int>& xy2) {
    const auto& [x1, y1] = xy1;
    const auto& [x2, y2] = xy2;
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    uint N;
    cin >> N;
    vector<pair<int, int>> xy(N);
    for (auto& [xi, yi] : xy) cin >> xi >> yi;

    double sum_distance = 0.0;
    vector<uint> p(N);
    for (uint i = 0; i < N; i++) p[i] = i;
    do {
        for (uint i = 1; i < N; i++) {
            sum_distance += distance(xy[p[i - 1U]], xy[p[i]]);
        }
    } while (next_permutation(p.begin(), p.end()));

    uint factN = N;
    while (--N) factN *= N;

    cout << setprecision(10) << sum_distance / factN << '\n';

    return 0;
}
