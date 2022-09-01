#include <bits/stdc++.h>
using namespace std;

#define ALL(v) (v).begin(), (v).end()

#define REP(i, n) for (size_t i = 0UL; i < (n); i++)
#define REP1(i, n) for (size_t i = 1UL; i <= (n); i++)

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ushort H1, W1, H2, W2;
    cin >> H1 >> W1;
    vector<vector<uint>> A(H1, vector<uint>(W1));
    for (auto &Ai : A)
        for (uint &Aij : Ai) cin >> Aij;

    cin >> H2 >> W2;
    vector<vector<uint>> B(H2, vector<uint>(W2));
    for (auto &Bi : B)
        for (uint &Bij : Bi) cin >> Bij;

    // Aのどの行、列を残すか
    vector<ushort> pH(H1, 0), pW(W1, 0);
    REP1(i, H2) pH[H1 - i] = 1;
    REP1(j, W2) pW[W1 - j] = 1;

    do {      // comb(H1, H2) <= comb(10, 5) = 252
        do {  // comb(W1, W2) <= comb(10, 5) = 252
            vector<ushort> pH_sorted, pW_sorted;
            REP(i, H1) if (pH[i]) pH_sorted.push_back(i);
            REP(j, W1) if (pW[j]) pW_sorted.push_back(j);

            // H2*W2 <= 100
            bool is_same = true;
            for (ushort i = 0; i < H2 && is_same; i++) {
                for (ushort j = 0; j < W2 && is_same; j++) {
                    uint pAij = A[pH_sorted[i]][pW_sorted[j]];
                    is_same = (pAij == B[i][j]);
                }
            }
            if (is_same) {
                cout << "Yes\n";
                return 0;
            }
        } while (next_permutation(ALL(pW)));
    } while (next_permutation(ALL(pH)));

    cout << "No\n";
    return 0;
}
