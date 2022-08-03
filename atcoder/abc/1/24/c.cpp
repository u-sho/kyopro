#include <algorithm>
#include <iostream>
#include <string>
int main() {
    using namespace std;
    string s;
    cin >> s;

    int ans_0 = 0;  // 0始まり
    int ans_1 = 0;  // 1始まり
    for (size_t i = 0UL; i < s.length(); ++i) {
        if (i % 2UL) {
            if (s.at(i) == '1') {
                ans_1++;
            } else {
                ans_0++;
            }
        } else {
            if (s.at(i) == '1') {
                ans_0++;
            } else {
                ans_1++;
            }
        }
    }

    cout << min(ans_0, ans_1) << endl;
    return 0;
}