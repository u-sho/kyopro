#include <cmath>
#include <climits> /* LLONG_MAX */

#include <string>
#include <vector>
#include <numeric> /* gcd, lcm, partial_sum, reduce*/
#include <iomanip> /* setprecision */
#include <iostream>
#include <algorithm>

using ll = long long; // c++11

const std::string ans[2] = { "No\n", "Yes\n" };

int main() {
    using namespace std;
    int n, m;
    cin >> n >> m;
    cout << ans[n == m] << endl;
    return 0;
}
