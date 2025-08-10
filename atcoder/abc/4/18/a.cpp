#include <bits/stdc++.h>
using namespace std;

bool ends_with(const string& s, const string& suffix) {
    if (s.length() < suffix.length()) return false;
    return equal(suffix.rbegin(), suffix.rend(), s.rbegin());
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    uint N;
    cin >> N;
    string S;
    cin >> S;
    cout << (ends_with(S, "tea") ? "Yes\n" : "No\n");

    return 0;
}
