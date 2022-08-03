#include <algorithm>
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::string;

int main(void) {
    char a;
    cin >> a;
    // int a, b;
    // cin >> a >> b;

    // int ans;
    // // int ans = ;
    // cout << ans << '\n';

    const string ans[2] = {"a\n", "A\n"};
    cout << ans[a <= 'Z'] << '\n';
    return 0;
}