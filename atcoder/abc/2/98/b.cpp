#include <bits/stdc++.h>
using namespace std;

using ullong = unsigned long long;

#define REP(i, n) for (size_t i = 0UL; i < (n); i++)
#define REP1(i, n) for (size_t i = 1UL; i < (n); i++)

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    unsigned N;
    cin >> N;

    vector<vector<unsigned>> A(N, vector<unsigned>(N)),
        B(N, vector<unsigned>(N));
    for (auto& Ai : A)
        for (unsigned& Aij : Ai) cin >> Aij;
    for (auto& Bi : B)
        for (unsigned& Bij : Bi) cin >> Bij;

    bool is_the_same = true;
    REP(i, N) {
        REP(j, N) {
            if (A[i][j] == 1 && B[i][j] != 1) {
                is_the_same = false;
                break;
            }
        }
        if (!is_the_same) break;
    }
    if (is_the_same) {
        cout << "Yes\n";
        return 0;
    }

    is_the_same = true;
    REP(i, N) {
        REP(j, N) {
            if (A[N - 1 - j][i] == 1 && B[i][j] != 1) {
                is_the_same = false;
                break;
            }
        }
        if (!is_the_same) break;
    }
    if (is_the_same) {
        cout << "Yes\n";
        return 0;
    }

    is_the_same = true;
    REP(i, N) {
        REP(j, N) {
            if (A[N - 1 - i][N - 1 - j] == 1 && B[i][j] != 1) {
                is_the_same = false;
                break;
            }
        }
        if (!is_the_same) break;
    }
    if (is_the_same) {
        cout << "Yes\n";
        return 0;
    }

    is_the_same = true;
    REP(i, N) {
        REP(j, N) {
            if (A[j][N - 1 - i] == 1 && B[i][j] != 1) {
                is_the_same = false;
                break;
            }
        }
        if (!is_the_same) break;
    }
    if (is_the_same) {
        cout << "Yes\n";
        return 0;
    }

    cout << "No\n";
    return 0;
}
