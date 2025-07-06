#include <bits/stdc++.h>
using namespace std;

const vector<vector<uint>> yes_list = {
    {1, 2, 3, 5, 4},
    {1, 2, 4, 3, 5},
    {1, 3, 2, 4, 5},
    {2, 1, 3, 4, 5}
};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    vector<uint> A(5);
    for (auto& a : A) cin >> a;

    cout << (ranges::count(yes_list, A) ? "Yes\n" : "No\n");

    return 0;
}
