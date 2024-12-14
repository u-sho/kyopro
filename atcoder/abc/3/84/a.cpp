#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    uint N;
    char c1, c2;
    string S;
    cin >> N >> c1 >> c2;
    cin >> S;
    for (auto &Si : S) {
        if (Si != c1) Si = c2;
    }
    cout << S << '\n';
}
