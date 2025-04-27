#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string T, U;
    cin >> T;
    cin >> U;

    for (uint i = 0; i + U.length() <= T.length(); i++) {
        // T[i, i+|U|) == U
        bool isIncluded = true;
        for (uint j = 0; j < U.length(); j++) {
            if (T[i + j] == '?') continue;
            if (T[i + j] == U[j]) continue;
            isIncluded = false;
        }
        if (isIncluded) {
            cout << "Yes\n";
            return 0;
        }
    }

    cout << "No\n";

    return 0;
}
