#include <bits/stdc++.h>
using namespace std;

const array<string, 2> s = {"No\n", "Yes\n"};

bool solve(const string& S) {
    int x = stoi(S.substr(3));
    if (x <= 0 || x >= 350 || x == 316) return false;
    return true;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string S;
    cin >> S;
    bool ans = solve(S);
    cout << s[ans];

    return 0;
}
