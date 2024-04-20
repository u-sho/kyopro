#include <bits/stdc++.h>
using namespace std;

#include <atcoder/all>
using namespace atcoder;

#define SORT(v)  std::ranges::sort(v)
#define ALL(v)   (v).begin(), (v).end()
#define LP(v, c) lower_bound(ALL(v), (c))
#define UP(v, c) upper_bound(ALL(v), (c))
#define BS(v, c) binary_search(ALL(v), (c))

#define REP(i, n)  for (size_t i = 0UL; i < (n); i++)
#define REP1(i, n) for (size_t i = 1UL; i < (n); i++)

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string S;
    cin >> S;
    uint n     = S.length();
    uint depth = 0;
    vector<uint> lparen, rparen;
    for (uint i = 0; i < n; i++) {
        if (S[i] == '(') {
            ++depth;
            lparen.push_back(i);
        } else if (S[i] == ')') {
            --depth;
            rparen.push_back(i);
        } else {
            if (depth & 1U) {
                if (S[i] <= 'Z') S[i] += 'a' - 'A';
                else S[i] -= 'a' - 'A';
            }
        }
    }

    return 0;
}
