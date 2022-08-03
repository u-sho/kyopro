#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> L(n);
    for (int &Li : L) cin >> Li;

    sort(L.begin(), L.end());

    int ans = 0;

    for (int i = 0; i < n - 2; ++i) {
        for (int j = i + 1; j < n - 1; ++j) {
            if (L.at(i) == L.at(j)) continue;
            for (int k = j + 1; k < n; ++k) {
                if (L.at(j) == L.at(k)) continue;
                if (L.at(i) + L.at(j) > L.at(k))
                    ans++;
                else
                    break;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
