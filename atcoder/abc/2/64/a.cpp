#include <bits/stdc++.h>
using namespace std;
int main(void) {
    const string atcoder = "atcoder";
    unsigned short L, R;
    cin >> L >> R;
    cout << atcoder.substr(L - 1, R - L + 1);
}