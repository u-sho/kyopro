#include <bits/stdc++.h>
using namespace std;

using Coordinates = pair<int, int>;

unsigned square_Euclidean_distance(const Coordinates &xy1,
                                   const Coordinates &xy2) {
    return (xy1.first - xy2.first) * (xy1.first - xy2.first) +
           (xy1.second - xy2.second) * (xy1.second - xy2.second);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    unsigned N, D;
    cin >> N >> D;
    vector<pair<int, int>> XY(N);
    for (pair<int, int> &XYi : XY) cin >> XYi.first >> XYi.second;

    queue<unsigned> sources;
    sources.push(0);
    vector<bool> has_virus(N, false);
    has_virus[0] = true;
    while (!sources.empty()) {
        unsigned source = sources.front();
        sources.pop();
        for (unsigned i = 1; i < N; i++) {
            if (has_virus[i]) continue;
            if (square_Euclidean_distance(XY[source], XY[i]) > D * D) continue;
            has_virus[i] = true;
            sources.push(i);
        }
    }

    for (unsigned i = 0; i < N; i++) {
        cout << (has_virus[i] ? "Yes\n" : "No\n");
    }

    return 0;
}
