#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s;
    cin >> t;

    int ans = 1000000000;
    for (size_t i = 0; i <= s.length() - t.length(); i++) {
        int sum = 0;
        for (size_t j = 0; j < t.length(); j++) {
            // tがsの部分文字列となるためには，sを何回書き換えれば良いか
            if (t.at(j) != s.at(i + j)) ++sum;
        }
        ans = min(ans, sum);
    }

    cout << ans << "\n";

    return 0;
}
