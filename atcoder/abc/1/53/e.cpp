#include <bits/stdc++.h>
constexpr int INF = 100000;

bool opeB(const std::pair<int, int> &ab1, const std::pair<int, int> &ab2) {
    return ab1.second < ab2.second;
}

int main() {
    // o(NH) のナップザックっぽい問題っぽい
    using namespace std;
    int h, n;
    cin >> h >> n;
    vector<pair<int, int> > ab;
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        ab[i] = make_pair(a, b);
    }

    sort(ab.begin(), ab.end());  // aの昇順

    // 枝狩
    int lwbnd = INF;
    for (int i = 0; i < n; i++) {
        if (ab[i].first > h) {
            lwbnd = i + 1;
            break;
        }
    }
    sort(ab.begin() + (lwbnd - 1), ab.end(), opeB);
    if (lwbnd != INF)
        for (; n > lwbnd; n--) ab.erase(ab.begin() + lwbnd);

    
    return 0;
}