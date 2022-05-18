#include <iostream>
#include <string>
#define L '('
#define R ')'

int main(void) {
    using std::cin;
    using std::cout;
    using std::string;
    int n;
    cin >> n;
    string s;
    cin >> s;

    int nest   = 0;
    int need_l = 0;
    for (auto &se : s) {
        if (se == L)
            nest++;
        else if (nest == 0)
            need_l++;
        else
            nest--;
    }
    int need_r = nest;

    for (int i = 0; i < need_l; ++i) cout << L;
    cout << s;
    for (int i = 0; i < need_r; ++i) cout << R;
    cout << '\n';

    return 0;
}
