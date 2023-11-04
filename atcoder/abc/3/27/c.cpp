#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define REP(i, n) for (unsigned i = 0U; i < (n); i++)

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // input
    unsigned A[9][9];
    REP(i, 9U) REP(j, 9U) cin >> A[i][j];

    // solve
    // check if A is valid for sudoku

    // 行
    REP(i, 9U) {
        vector<bool> valid(9, false);
        REP(j, 9U) valid[A[i][j] - 1] = true;
        REP(j, 9U) {
            if (!valid[j]) {
                cout << "No\n";
                return 0;
            }
        }
    }

    // 列
    REP(j, 9U) {
        vector<bool> valid(9, false);
        REP(i, 9U) valid[A[i][j] - 1] = true;
        REP(i, 9U) {
            if (!valid[i]) {
                cout << "No\n";
                return 0;
            }
        }
    }

    // 3x3
    for (unsigned i = 0; i < 9U; i += 3U) {
        for (unsigned j = 0; j < 9U; j += 3U) {
            vector<bool> valid(9, false);
            REP(k, 3U) REP(l, 3U) valid[A[i + k][j + l] - 1] = true;

            REP(k, 9U) {
                if (!valid[j]) {
                    cout << "No\n";
                    return 0;
                }
            }
        }
    }

    cout << "Yes\n";

    return 0;
}
