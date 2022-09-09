#include <bits/stdc++.h>
using namespace std;

[[nodiscard]] bool is_split(const string &S) {
    if (S.size() != 10) assert(false);
    if (S[0] == '1') return false;

    vector<bool> v;
    v.push_back(S[6] == '1');
    if ((S[3] == '1') ^ v.back()) v.push_back(!v.back());
    if ((S[1] == '1' | S[7] == '1') ^ v.back()) v.push_back(!v.back());
    if ((S[4] == '1') ^ v.back()) v.push_back(!v.back());
    if ((S[2] == '1' | S[8] == '1') ^ v.back()) v.push_back(!v.back());
    if ((S[5] == '1') ^ v.back()) v.push_back(!v.back());
    if ((S[9] == '1') ^ v.back()) v.push_back(!v.back());

    for (uint i = 1; i < v.size() - 1; i++) {
        if (v[i - 1] & !v[i] & v[i + 1]) return true;
    }
    return false;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string S;
    cin >> S;

    cout << (is_split(S) ? "Yes\n" : "No\n");

    return 0;
}
