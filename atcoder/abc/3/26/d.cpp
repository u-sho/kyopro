#include <bits/stdc++.h>
using namespace std;

#define SORT(v)    std::ranges::sort(v)
#define ALL(v)     (v).begin(), (v).end()
#define REP(i, n)  for (size_t i = 0UL; i < (n); i++)
#define REP1(i, n) for (size_t i = 1UL; i < (n); i++)

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    uint N;
    cin >> N;
    string R;
    cin >> R;
    string C;
    cin >> C;

    // 全探索
    if (N == 3U) {
        vector<string> A = {"...", "...", "..."};
        if (R[0] != C[0]) cout << "No\n";
        else if (R[0] == R[1] || R[1] == R[2] || R[2] == R[0]) cout << "No\n";
        else if (C[0] == C[1] || C[1] == C[2] || C[2] == C[0]) cout << "No\n";
        else {
            A[0]    = C;
            A[1][0] = R[1];
            A[2][0] = R[2];
            if (R[1] == C[1]) {
                A[1][1] = R[2];
                A[2][2] = R[1];
                A[1][2] = A[2][1] = R[0];
            } else {
                A[1][2] = R[2];
                A[2][1] = R[1];
                A[1][1] = A[2][2] = R[0];
            }
            cout << "Yes\n";
            cout << A[0] << "\n" << A[1] << "\n" << A[2] << "\n";
        }
        return 0;
    }

    if (N == 4U) {
        vector<string> A(N, ".ABC");
        vector<bool> checked_C(N, false);
        do {              // 4! = 24
            do {          // 4! = 24
                do {      // 4! = 24
                    do {  // 4! = 24
                        for (uint j = 0; j < N; j++) {
                            bool cA = false, cB = false, cC = false;
                            for (uint i = 0; i < N; i++) {
                                if (A[i][j] == 'A') {
                                    if (cA) goto LABEL;
                                    else cA = true;
                                }
                                if (A[i][j] == 'B') {
                                    if (cB) goto LABEL;
                                    else cB = true;
                                }
                                if (A[i][j] == 'C') {
                                    if (cC) goto LABEL;
                                    else cC = true;
                                }
                            }
                            if (!(cA && cB && cC)) goto LABEL;
                        }

                        for (uint i = 0; i < N; i++) checked_C[i] = false;
                        for (uint i = 0; i < N; i++) {
                            bool checked_R = false;
                            for (uint j = 0; j < N; j++) {
                                if (A[i][j] == '.') continue;
                                if (!checked_R) {
                                    if (A[i][j] == R[i]) checked_R = true;
                                    else goto LABEL;
                                }
                                if (!checked_C[j]) {
                                    if (A[i][j] == C[j]) checked_C[j] = true;
                                    else goto LABEL;
                                }
                            }
                        }
                        for (uint i = 0; i < N; i++) {
                            if (!checked_C[i]) goto LABEL;
                        }
                        cout << "Yes\n";
                        cout << A[0] << "\n";
                        cout << A[1] << "\n";
                        cout << A[2] << "\n";
                        cout << A[3] << "\n";
                        return 0;
                    LABEL:
                        continue;
                    } while (next_permutation(ALL(A[3])));
                } while (next_permutation(ALL(A[2])));
            } while (next_permutation(ALL(A[1])));
        } while (next_permutation(ALL(A[0])));
    }

    if (N == 5U) {
        vector<string> A(N, "..ABC");
        vector<bool> checked_C(N, false);
        do {  // 5! = 120
              // A[0]の先頭がR[0]か：20通り
            for (uint i = 0; i < N; i++) {
                if (A[0][i] == '.') continue;
                if (A[0][i] == R[0]) break;
                else goto CONTINUE_0;
            }
            do {  // 5! = 120 : 20通り
                for (uint i = 0; i < N; i++) {
                    if (A[1][i] == '.') continue;
                    if (A[1][i] == R[1]) break;
                    else goto CONTINUE_1;
                }
                do {  // 5! = 120 : 20通り
                    for (uint i = 0; i < N; i++) {
                        if (A[2][i] == '.') continue;
                        if (A[2][i] == R[2]) break;
                        else goto CONTINUE_2;
                    }
                    do {  // 5! = 120 : 20通り
                        for (uint i = 0; i < N; i++) {
                            if (A[3][i] == '.') continue;
                            if (A[3][i] == R[3]) break;
                            else goto CONTINUE_3;
                        }
                        do {  // 5! = 120 : 20通り
                            for (uint i = 0; i < N; i++) {
                                if (A[4][i] == '.') continue;
                                if (A[4][i] == R[4]) break;
                                else goto G_CONTINUE;
                            }

                            // 列にABC一つずつか
                            for (uint j = 0; j < N; j++) {
                                bool cA = false, cB = false, cC = false;
                                for (uint i = 0; i < N; i++) {
                                    if (A[i][j] == 'A') {
                                        if (cA) goto G_CONTINUE;
                                        else cA = true;
                                    }
                                    if (A[i][j] == 'B') {
                                        if (cB) goto G_CONTINUE;
                                        else cB = true;
                                    }
                                    if (A[i][j] == 'C') {
                                        if (cC) goto G_CONTINUE;
                                        else cC = true;
                                    }
                                }
                                if (!(cA && cB && cC)) goto G_CONTINUE;
                            }

                            // 列の先頭が C[i] か
                            for (uint i = 0; i < N; i++) checked_C[i] = false;
                            for (uint i = 0; i < N; i++) {
                                for (uint j = 0; j < N; j++) {
                                    if (A[i][j] == '.') continue;
                                    if (!checked_C[j]) {
                                        if (A[i][j] == C[j])
                                            checked_C[j] = true;
                                        else goto G_CONTINUE;
                                    }
                                }
                            }
                            for (uint i = 0; i < N; i++) {
                                if (!checked_C[i]) goto G_CONTINUE;
                            }

                            cout << "Yes\n";
                            cout << A[0] << "\n";
                            cout << A[1] << "\n";
                            cout << A[2] << "\n";
                            cout << A[3] << "\n";
                            cout << A[4] << "\n";
                            return 0;

                        G_CONTINUE:
                            continue;
                        } while (next_permutation(ALL(A[4])));
                    CONTINUE_3:
                        continue;
                    } while (next_permutation(ALL(A[3])));
                CONTINUE_2:
                    continue;
                } while (next_permutation(ALL(A[2])));
            CONTINUE_1:
                continue;
            } while (next_permutation(ALL(A[1])));
        CONTINUE_0:
            continue;
        } while (next_permutation(ALL(A[0])));
    }

    cout << "No\n";

    return 0;
}
