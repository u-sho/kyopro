#include <algorithm>
#include <iostream>
using namespace std;

int sentou_matubi[10][10];

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        int ketasu =
            i < 10 ? 1
                   : i < 100
                         ? 10
                         : i < 1000
                               ? 100
                               : i < 10000 ? 1000 : i < 100000 ? 10000 : 100000;
        int sentou = i / ketasu;
        int matubi = i % 10;
        sentou_matubi[sentou][matubi]++;
    }

    long long ans = 0LL;
    for (int i = 1; i <= 9; ++i) {
        for (int j = 1; j <= 9; ++j) {
            int ij = sentou_matubi[i][j];
            int ji = sentou_matubi[j][i];
            ans += ij * ji;
        }
    }

    cout << ans << endl;
    return 0;
}