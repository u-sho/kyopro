#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

template <typename T>
std::istream &operator>>(std::istream &is, std::vector<T> &v) {
    for (T &in : v) is >> in;
    return is;
}

int main(void) {
    using std::cin;
    using std::cout;
    using std::endl;
    using std::size_t;
    using std::sort;
    using std::vector;

    int n, m;  // <=1e5
    cin >> n >> m;
    vector<int> a(n);
    cin >> a;

    sort(a.begin(), a.end());

    long long removed_sum = 0LL;
    for (int i = 1; i <= m; ++i) {
        int ab = a.back() / 2;
        a.pop_back();

        decltype(a)::iterator it = std::lower_bound(a.begin(), a.end(), ab);
        if (a.end() - it < m - i) {
            ++i;
            ab /= 2;
            it = std::lower_bound(a.begin(), a.end(), ab);
        }
        a.insert(it, ab);  // a.end()-itの時間計算量(線形)
    }

    long long sum = std::accumulate(a.begin(), a.end(), 0LL);

    cout << sum << endl;

    return 0;
}