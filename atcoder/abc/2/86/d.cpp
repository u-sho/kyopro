#include <bits/stdc++.h>
using namespace std;

int main(void) {
    unsigned N, X;
    cin >> N >> X;
    vector<pair<unsigned, unsigned>> AB(N);  // Ai円硬貨をBi円持っている
    for (auto& ABi : AB) cin >> ABi.first >> ABi.second;

    // (j*Ai)円硬貨を1枚ずつ持っている（j=1,2,...,Bi）
    vector<unsigned> payable;
    payable.push_back(0);
    for (const auto& ABi : AB) {
        for (unsigned j = 1; j <= ABi.second; j++) {
            if (j * ABi.first <= X)
                payable.push_back(j * ABi.first);
            else
                break;
        }
    }

    for (unsigned i = 0; i <= X; i++) {
        if (payable.at(i)) {
        }
    }

    cout << (payable[X] ? "Yes\n" : "No\n");
    return 0;
}
