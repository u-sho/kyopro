#include <bits/stdc++.h>
const std::string ans[2] = {"No\n", "Yes\n"};

int main() {
    using namespace std;
    string S;
    cin >> S;
    bool isKaibun = true;

    int n = S.length();  // n は奇数
    for (int i = 0; i < n / 2 && isKaibun; i++) {
        if (S[i] != S[n - i - 1]) isKaibun = false;
    }
    n /= 2;
    for (int i = 0; i < n && isKaibun; i++) {
        if (S[i] != S[n - i - 1]) isKaibun = false;
    }
    for (int i = 0; i < n && isKaibun; i++) {
        if (S[n + 1 + i] != S[S.length() - 1 - i]) isKaibun = false;
    }

    cout << ans[isKaibun];
    return 0;
}