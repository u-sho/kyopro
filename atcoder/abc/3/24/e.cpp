#include <bits/stdc++.h>
using namespace std;

#include <atcoder/all>
using namespace atcoder;

#define ALL(v)   (v).begin(), (v).end()
#define SORT(v)  sort(ALL(v))
#define LP(v, c) lower_bound(ALL(v), (c))
#define UP(v, c) upper_bound(ALL(v), (c))
#define BS(v, c) binary_search(ALL(v), (c))

#define REP(i, n)  for (size_t i = 0UL; i < (n); i++)
#define REP1(i, n) for (size_t i = 1UL; i < (n); i++)

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    uint64_t N;
    string T;
    cin >> N >> T;
    vector<string> S(N);
    for (string &Si : S) cin >> Si;

    vector<string> S_notIncludeT;
    for (const string &Si : S) {           // 5e5
        if (Si.find(T) == string::npos) {  // O( |Si| )
            S_notIncludeT.push_back(Si);
        }
    }
    uint64_t s = S_notIncludeT.size();
    uint64_t ans = N * N - s * (s - 1ULL);  // (全体) - (T を含まないものどうし)

    // 後半部分がTの前半部分と一致
    // 前半部分がTの後半部分と一致

    return 0;
}
