#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string S, T;
    cin >> S;
    cin >> T;

    uint i = 0;
    vector<uint> A;
    for (const char& Si : S) {
        while (i < T.length() && T[i++] != Si)
            ;
        A.push_back(i);
    }

    for (const uint& Ai : A) {
        cout << Ai;
        if (Ai != A.back()) {
            cout << ' ';
        } else {
            cout << '\n';
        }
    }
    return 0;
}
