#include <iostream>
#include <string>
using namespace std;
int main(void) {
    int k;
    string s;
    cin >> k;
    cin >> s;
    if (s.length() <= k) {
        cout << s << endl;
        return 0;
    }
    cout << s.substr(0, k) << "...\n";
    return 0;
}