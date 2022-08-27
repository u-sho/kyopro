#include <bits/stdc++.h>
using namespace std;
int main(void) {
    string S;
    cin >> S;
    size_t T = S.length();
    char center_char = S[T / 2];
    cout << center_char << '\n';
    return 0;
}