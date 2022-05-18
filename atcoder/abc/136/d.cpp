#include <algorithm>  // std::fill
#include <iostream>
#include <string>
#include <vector>

int main(void) {
    using namespace std;
    string s;
    cin >> s;

    vector<int> ans(s.length());
    fill(ans.begin(), ans.end(), 0);

    int r_count = 1;  // RLの子のうち，Rのみを考える
    for (int i = 1; i < s.length(); ++i) {
        if (s.at(i) == 'R') {
            r_count++;
        } else if (r_count) {  // 左にRがr_count個連なるL

            // RLのLから偶数マス離れたR
            ans.at(i) = r_count / 2;
            // RLのRから偶数マス離れたR
            ans.at(i - 1) = (r_count + 1) / 2;

            // 次のRLの子を数えるので0にする
            r_count = 0;
        }
    }

    int l_count = 1;  // RLの子のうち，Lのみを考える
    for (int i = s.length() - 2; i >= 0; --i) {
        if (s.at(i) == 'L') {
            l_count++;
        } else if (l_count) {  // 右にLがl_count個連なるR

            // RLのRから偶数マス離れたL
            ans.at(i) += l_count / 2;
            // RLのLから偶数マス離れたL
            ans.at(i + 1) += (l_count + 1) / 2;

            // 次のRLの子を数えるので0にする
            l_count = 0;
        }
    }

    for (int i = 0; i < ans.size(); ++i) {
        cout << ans.at(i) << (i + 1 != ans.size() ? ' ' : '\n');
    }

    return 0;
}