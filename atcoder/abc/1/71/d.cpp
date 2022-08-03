#include <algorithm>
#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::vector;

int main() {
    int n;
    cin >> n;
    vector<int> aval(100005);
    std::fill(aval.begin(), aval.end(), 0);
    for (int i = 1; i <= n; ++i) {
        int ai;
        cin >> ai;
        aval.at(ai)++;
    }

    long s = 0;
    for (int i = 1; i <= 100000; ++i) {
        s += aval.at(i) * (long)i;
    }
    int q;
    cin >> q;
    for (int qi = 0; qi < q; qi++) {
        int b, c;
        cin >> b >> c;
        s -= aval.at(b) * (long)b;
        s += aval.at(b) * (long)c;
        aval.at(c) += aval.at(b);
        aval.at(b) = 0;
        cout << s << '\n';
    }
    return 0;
}