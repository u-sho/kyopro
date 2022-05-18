#include <bits/stdc++.h>
using namespace std;

string ans[2] = {"No\n", "Yes\n"};
int c[10], cnt[10];

bool is_x8(const int *cnt) {
    for (int i = 112; i < 1000; i += 8) {
        for (int j = 0; j < 10; j++) c[j] = cnt[j];
        for (const char ic : to_string(i)) c[ic - '0']--;

        if (all_of(c, c + 10, [](int ci) { return ci >= 0; })) return true;
    }
    return false;
}

int main() {
    string S;
    cin >> S;

    if (S.length() == 1UL) return ((cout << ans[S == "8"]), 0);

    if (S.length() > 2UL) {
        for (const char &Si : S) cnt[Si - '0']++;
        cout << ans[is_x8(cnt)];
        return 0;
    }

    if (stoi(S) % 8 == 0) return ((cout << ans[1]), 0);
    swap(S[0], S[1]);
    cout << ans[stoi(S) % 8 == 0];

    return 0;
}
