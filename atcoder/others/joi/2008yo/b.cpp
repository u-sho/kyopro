#include <iostream>
#include <string>
using namespace std;

int main(void) {
    string s;
    cin >> s;

    unsigned count_JOI = 0u;
    unsigned count_IOI = 0u;
    for (unsigned i = 0u; i + 2u < s.length(); i++) {
        if (s[i] == 'J' && s[i + 1] == 'O' && s[i + 2] == 'I') {
            ++count_JOI;
        }
        if (s[i] == 'I' && s[i + 1] == 'O' && s[i + 2] == 'I') {
            ++count_IOI;
        }
    }

    cout << count_JOI << '\n' << count_IOI << '\n';
    return 0;
}