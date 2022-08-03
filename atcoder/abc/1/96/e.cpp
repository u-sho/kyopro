#include <bits/stdc++.h>

using namespace std;
using ui   = unsigned;
using lli  = long long;
using ulli = unsigned long long;

#define ALL(v) v.begin(), v.end()
#define SORT(v) sort((v).begin(), (v).end())
#define REP(i, n) for (size_t i = 0UL; i < (n); i++)
#define REP1(i, n) for (size_t i = 1UL; i < (n); i++)

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    size_t N;
    cin >> N;
    vector<int> ain(N), tin(N);
    REP(i, N) cin >> ain[i] >> tin[i];
    vector<int> a, t;
    REP(i, N - 1UL) {
        if (tin[i] == 1 && tin[i + 1] == 1) {
            ain[i + 1] += ain[i];
            continue;
        }
        if (tin[i] == 2 && tin[i + 1] == 2) {
            ain[i + 1] = max(ain[i], ain[i + 1]);
            continue;
        }
        if (tin[i] == 3 && tin[i + 1] == 3) {
            ain[i + 1] = min(ain[i], ain[i + 1]);
            continue;
        }
        a.push_back(ain[i]);
        t.push_back(tin[i]);
    }
    a.push_back(ain.back());
    t.push_back(tin.back());

    size_t Q;
    cin >> Q;
    vector<int> x(Q);
    for (int &xi : x) cin >> xi;

    return 0;
}
