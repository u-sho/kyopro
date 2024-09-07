#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string S, T;
    cin >> S;
    cin >> T;

    vector<string> X;
    while (S != T) {
        bool flag = false;
        for (uint i = 0; i < S.length(); i++) {
            if (S[i] > T[i]) {
                S[i] = T[i];
                X.push_back(S);
                flag = true;
                break;
            }
        }
        if (flag) continue;
        for (int i = S.length() - 1; i >= 0; i--) {
            if (S[i] < T[i]) {
                S[i] = T[i];
                X.push_back(S);
                break;
            }
        }
    }

    cout << X.size() << '\n';
    for (const auto &Xi : X) {
        cout << Xi << '\n';
    }

    return 0;
}
