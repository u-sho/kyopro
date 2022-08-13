#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    unsigned t;
    cin >> t;
    while (t--) {
        // inputs
        size_t n;
        cin >> n;
        vector<int> a(n);
        for (int &ai : a) cin >> ai;

        // solve----------------------------------------------------------
        // get next signed element positions
        vector<size_t> n_p(n, n), n_m(n, n);
        for (size_t i = n - 1UL; i; i--) {
            n_p.at(i - 1UL) = ((a.at(i) > 0) ? i : n_p.at(i));
            n_m.at(i - 1UL) = ((a.at(i) < 0) ? i : n_m.at(i));
        }

        // i < j, a[i] > 0 > a[j] --> while((--a[i] && ++a[j]))
        for (size_t i = ((a.at(0UL) > 0) ? 0UL : n_p.at(0UL)), j = 0UL; i < n;
             i = ((a.at(i) > 0) ? i : n_p.at(i))) {
            if (i >= j) j = i;
            if (a.at(j) >= 0) j = n_m.at(j);
            if (j >= n) break;

            int dif_abs = min(a.at(i), -a.at(j));
            a.at(i) -= dif_abs;
            a.at(j) += dif_abs;
        }

        // sum of plus elements
        long long sum_p = 0LL;
        for (size_t i = ((a.at(0UL) > 0) ? 0UL : n_p.at(0UL)); i < n;
             i        = n_p.at(i)) {
            sum_p += a.at(i);
        }

        // output
        cout << sum_p << "\n";
    }

    return 0;
}
