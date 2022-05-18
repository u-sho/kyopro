#include <iostream>
const std::string ans[2] = {"No\n", "Yes\n"};

int main() {
    using namespace std;
    string s;
    cin >> s;
    cout << ans[(s[0] != s[1] || s[2] != s[1])] << endl;
    return 0;
}