#include <bits/stdc++.h>
using namespace std;
int main() {
    uint N;
    string T, A;
    cin >> N;
    cin >> T;
    cin >> A;

    bool ans = false;
    for (uint i = 0; i < N; i++) {
        ans = ans || (T[i] == A[i] && T[i] == 'o');
    }
    cout << (ans ? "Yes\n" : "No\n");
}
