#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string S;
    cin >> S;

    if (S.length() < 3) {
        cout << "0\n";
        return 0;
    }

    double 充填率 = 0.0;
    for (uint ibegin = 0; ibegin < S.length() - 2; ibegin++) {
        if (S[ibegin] != 't') continue;
        for (uint iend = ibegin + 3; iend <= S.length(); iend++) {
            if (S[iend-1] != 't') continue;

            uint x = 0;
            for (uint i = ibegin; i < iend; i++) {
                if (S[i] == 't') x++;
            }
            充填率 = max(充填率, (x - 2.0) / (iend - ibegin - 2.0));
        }
    }

    cout << fixed << setprecision(15) << 充填率 << '\n';

    return 0;
}
