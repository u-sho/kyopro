#include <iostream>
#include <string>
using namespace std;
int main() {
    string S;
    cin >> S;
    if (S[0] != S[1] && S[0] != S[2]) {
        cout << "1\n";
        return 0;
    }
    if (S[1] != S[0] && S[1] != S[2]) {
        cout << "2\n";
        return 0;
    }
    for (size_t i = 2z; i < S.length(); i++) {
        if (S[i] != S[i - 1z] && S[i] != S[i - 2z]) {
            cout << i + 1z << '\n';
            return 0;
        }
    }
}