#include <bits/stdc++.h>
using namespace std;
int main() {
    unsigned N, M;
    cin >> N >> M;
    vector<string> C(N);
    for (string &Ci : C) cin >> Ci;
    vector<string> D(M);
    for (string &Di : D) cin >> Di;
    unsigned P0;
    cin >> P0;
    vector<unsigned> P(M);
    for (unsigned &Pi : P) cin >> Pi;

    unsigned sum_price = 0U;
    for (const string &Ci : C) {
        unsigned Ci_price = P0;
        for (unsigned j = 0; j < M; j++) {
            if (Ci == D[j]) {
                Ci_price = P[j];
                break;
            }
        }
        sum_price += Ci_price;
    }
    cout << sum_price << '\n';
    return 0;
}