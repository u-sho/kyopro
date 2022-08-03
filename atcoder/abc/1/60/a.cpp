#include <iostream>
const std::string ans[2] = {"No\n", "Yes\n"};

int main() {
    using namespace std;
    string s;
    cin >> s;
    cout << ans[(s[2] == s[3] && s[4] == s[5])] << endl;
    return 0;
}