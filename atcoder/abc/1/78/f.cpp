#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> cnt_a(n + 1, 0);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
        cnt_a[a[i]]++;
    }

    vector<int> cnt_b(n + 1, 0);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b.at(i);
        cnt_b[b[i]]++;
    }

    for (int i = 1; i <= n; i++) {
        if (cnt_a[i] + cnt_b[i] > n) {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";
    vector<int> same_idx;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) same_idx.push_back(i);
    }
    if (same_idx.size() == 0) {
        for (int i = 0; i < n; i++) cout << b[i] << (i == n - 1 ? "\n" : " ");
        return 0;
    }

    deque<int> next_same_idx = {n};
    for (int i = same_idx.size() - 1; i; i--) {
        if (b[same_idx[i]] != b[same_idx[i - 1]])
            next_same_idx.push_front(same_idx[i]);
        else {
            int idx = next_same_idx.front();
            next_same_idx.push_front(idx);
        }
    }

    vector<int> ans(n);
    for (int i = 0; i < same_idx.size(); i++) {
        }

    return 0;
}
