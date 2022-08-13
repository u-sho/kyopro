#include <bits/stdc++.h>
using namespace std;
const string a[2] = {"NO\n", "YES\n"};

int main() {
    int t;
    cin >> t;
    while (t--) {     // <= 1e4
        size_t n, k;  // 2<=k<=n<=3e5, k is even
        cin >> n >> k;
        string s;
        cin >> s;
        int zero_cnt = 0;
        int one_cnt  = 0;
        int question = 0;
        for (size_t i = 0UL; i < k - 1UL; i++) {
            if (s.at(i) == '0')
                zero_cnt++;
            else if (s.at(i) == '1')
                one_cnt++;
            else
                question++;
        }
        bool ans = true;
        for (size_t i = k - 1UL; i < n; i++) {
            if (s.at(i) == '0')
                zero_cnt++;
            else if (s.at(i) == '1')
                one_cnt++;
            else
                question++;

            if (abs(zero_cnt - one_cnt) > question) {
                ans = false;
                break;
            }

            if (s.at(i - k + 1UL) == '0')
                zero_cnt--;
            else if (s.at(i - k + 1UL) == '1')
                one_cnt--;
            else
                question--;
        }
        cout << a[ans];
    }
    return 0;
}
