#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
int main() {
    using namespace std;
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<int> S;
    for (int i = 0; i < n;) {
        int length = 0;
        for (int j = i; i < n; ++i) {
            if (s.at(j) != s.at(i)) break;
            if (s.at(j) == '0')
                --length;
            else
                ++length;
        }
        S.push_back(length);
        cout << S.back() << ' ';  //-----------
    }
    cout << '\n';  // ---------------------------

    vector<int> S_partial;
    S_partial.push_back(abs(S.at(0)));
    for (int i = 1; i < S.size(); ++i) {
        int t = abs(S.at(i)) + S_partial.at(i - 1);
        S_partial.push_back(t);
        cout << t << ' ';  //-----------------------
    }
    cout << '\n';  //-------------------------------

    if (S.size() <= 2 * k) {
        cout << S_partial.at(S.size() - 1) << endl;
        return 0;
    }

    int ans = 1;
    for (size_t i = 0UL; i < S.size(); ++i) {
        // sum (fst, lst]
        size_t fst = max(i - 1UL, 0UL);
        size_t lst = min(i + 2UL * k - 1UL, S.size() - 1UL);
        sum        = S_partial(lst) - S_partial(fst);

        if (S.at(i) > 0 && lst + 1UL < S.size()) {  // '10...'
            sum += S.at(lst + 1UL);
        }

        cout << sum << 's' << endl;

        ans = max(sum, ans);
    }

    cout << ans << endl;
    return 0;
}