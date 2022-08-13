#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int &pi : p) cin >> pi;
        for (int i = n - 1; i >= 0; i--) cout << p.at(i) << (i ? " " : "\n");
    }

    return 0;
}
