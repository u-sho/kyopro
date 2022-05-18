#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string S;
    cin >> S;
    reverse(S.begin(), S.end());

    unsigned long long ans = 0ULL;
    vector<unsigned> char_num(30UL, 0U);
    for (size_t i = 1UL; i < S.length(); i++) {
        char_num[S[i - 1UL] - 'a']++;
        if (S[i - 1UL] != S[i]) continue;

        ans += (unsigned long long)(i - char_num[S[i] - 'a']);
        fill(char_num.begin(), char_num.end(), 0U);
        char_num[S[i] - 'a'] = i;
    }

    cout << ans << "\n";

    return 0;
}
