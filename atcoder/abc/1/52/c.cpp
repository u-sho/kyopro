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
    int n;
    cin >> n;
    vector<int> P;
    for (int i = 0; i < n; i++){
        int p;
        cin >> p;
        P.push_back(p);
    }

    int min_p = P[0];
    int ans = 1;
    for (int i = 1; i < n; i++)
    {
        if (P[i]<min_p) {
            min_p = P[i];
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
