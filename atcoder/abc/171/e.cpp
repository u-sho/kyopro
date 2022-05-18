#include <algorithm>
#include <bitset>
#include <iostream>
#include <vector>
using std::bitset;
using std::cin;
using std::cout;
using std::vector;

int main() {
    int n;
    cin >> n;
    vector<bitset<32>> a;
    for (int i = 0; i < n; ++i) {
        long ai;
        cin >> ai;
        bitset<32> aib(ai);
        a.push_back(aib);
    }
    vector<bool> inv(32);
    std::fill(inv.begin(), inv.end(), false);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 32; ++j) {
            if (a[i][j]) inv[j] = !inv[j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 32; ++j) {
            if (inv[j]) a[i].flip(j);
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << a[i].to_ulong() << (i + 1 != n ? ' ' : '\n');
    }
    return 0;
}