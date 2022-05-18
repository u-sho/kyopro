#include <iostream>
#include <vector>
using namespace std;

using XY = pair<int, int>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // inputs
    int N;
    cin >> N;
    vector<XY> xy(N);
    for (XY &xyi : xy) cin >> xyi.first >> xyi.second;

    // solve
    long long dist = 0LL;
    XY edge        = xy[0];
    for (int i = 1; i < N; i++) {
        long long crr_dist =
            abs(xy[i].first - xy[0].first) + abs(xy[i].second - xy[0].second);
        dist = max(dist, crr_dist);
        if (dist == crr_dist) edge = xy[i];
    }

    for (int i = 0; i < N; i++) {
        long long crr_dist =
            abs(xy[i].first - edge.first) + abs(xy[i].second - edge.second);
        dist = max(dist, crr_dist);
    }

    // output
    cout << dist << "\n";

    return 0;
}
