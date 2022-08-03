#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string X;
    cin >> X;

    auto idx = X.find_first_of('.');
    cout << X.substr(0, idx) << "\n";

    return 0;
}
