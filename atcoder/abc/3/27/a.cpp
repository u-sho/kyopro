#include <iostream>
#include <string>
using namespace std;

int main() {
    unsigned int N;
    cin >> N;
    string S;
    cin >> S;

    for (unsigned int i = 1U; i < N; i++) {
        if (S[i - 1] == 'a' && S[i] == 'b') {
            cout << "Yes\n";
            return 0;
        }
        if (S[i - 1] == 'b' && S[i] == 'a') {
            cout << "Yes\n";
            return 0;
        }
    }

    cout << "No\n";
    return 0;
}