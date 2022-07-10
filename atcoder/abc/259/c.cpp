#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (size_t i = 0UL; i < (n); i++)
#define REP2(i, n) for (size_t i = 2UL; i < (n); i++)

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string S, T;
    cin >> S;
    cin >> T;

    if (S == T) {
        cout << "Yes\n";
        return 0;
    }

    if (S.length() >= T.length()) {
        cout << "No\n";
        return 0;
    }

    if (S.substr(0UL, 2UL) != T.substr(0UL, 2UL)) {
        cout << "No\n";
        return 0;
    }
    REP2(i, S.length()) {
        if (S[i] == T[i]) continue;
        if (S[i - 1] == S[i - 2] && T[i] == T[i - 1]) {
            S.insert(i - 1, T.substr(i, 1UL));
        } else {
            cout << "No\n";
            return 0;
        }
    }

    if (S == T) {
        cout << "Yes\n";
        return 0;
    }

    if (S.length() >= T.length()) {
        cout << "No\n";
        return 0;
    }

    if (S.substr(S.length() - 2) != T.substr(T.length() - 2)) {
        cout << "No\n";
        return 0;
    }

    cout << "Yes\n";

    return 0;
}
