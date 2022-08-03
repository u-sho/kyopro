#include <bits/stdc++.h>

template <typename T1, typename T2>
std::ostream &operator<<(std::ostream &os, const std::pair<T1, T2> &p) {
    os << p.first << " " << p.second << "\n";
    return os;
}

int main() {
    int n;
    std::vector<int> a;
    std::cin >> n;
    a.resize(n);
    for (int &ai : a) std::cin >> ai;

    std::sort(a.begin(), a.end());
    std::pair<int, int> ans = {a.at(n - 1), 0};
    if (n == 2) {
        std::cout << ans;
        return 0;
    }

    // comb(k,r)を考える
    int k        = ans.first;
    auto it_even = std::lower_bound(a.begin(), a.end(), k / 2);

    int r;
    // r == k/2
    if (it_even < a.end()) {
        r = *it_even;
        if (k / 2 - ans.second > k / 2 - (std::min(r, k - r))) ans.second = r;
    }
    // r == k/2 -1
    if (it_even > a.begin()) {
        r = *(it_even - 1);
        if (k / 2 - ans.second > k / 2 - (std::min(r, k - r))) ans.second = r;
    }
    // r == k/2 + 1
    if (it_even + 1 < a.end()) {
        r = *(it_even + 1);
        if (k / 2 - ans.second > k / 2 - (std::min(r, k - r))) ans.second = r;
    }

    std::cout << ans;
    return 0;
}