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

int GetDegit(int n) {
    return log10(n) + 1;
}

int main() {
    using namespace std;
    int n;
    cin >> n;

    int match[10][10]; // 1-9
    fill(match[0], match[10], 0);
    for (int i = 1; i <= n; i++){
        int d = i<10 ? 1 :
                i<100 ? 10 :
                i<1000 ? 100 :
                i<10000 ? 1000 :
                i<100000 ? 10000 :
                100000;
        int s = i<10 ? i : i/d;
        int e = i % 10;
        match[s][e]++;
    }
    ll ans = 0LL;
    for (int i = 1; i < 10; i++){
        for (int j = i; j < 10; j++){
            if(j==i)
                ans += match[i][j] * match[i][j];
            else {
                ans += 2 * match[i][j] * match[j][i];
            }
        }
    }

    cout << ans << endl;
    return 0;
}
