#include <iostream>
#include <unordered_set>
using namespace std;
using lli = unsigned long long;

int main(void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    lli N;
    cin >> N;

    unordered_set<lli> describable_num;
    for (lli i = 2LL; i * i <= N; ++i)
        for (lli i2 = i * i; i2 <= N; i2 *= i) {
            describable_num.insert(i2);
        }

    cout << N - describable_num.size() << "\n";
}
