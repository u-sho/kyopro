#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    int ans = 1;
    if (S.at(0) == S.at(1) && S.at(1) == 'R') ans++;
    if (S.at(1) == S.at(2) && S.at(1) == 'R') ans++;
    if (S.at(0) == S.at(1) && S.at(1) == S.at(2) && S.at(1) == 'S') ans = 0;

    cout << ans << endl;

    return 0;
}
