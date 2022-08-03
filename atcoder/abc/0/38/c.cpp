#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::vector;

long long sum(int n) { return (long long)n * ((long long)n + 1ll) / 2ll; }

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int &ai : a) cin >> ai;

    long long res = 0LL;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; i + j < N; ++j) {
            if (i + j + 1 >= N) {
                res += sum(j + 1);
                i = N;
                break;
            }
            if (a.at(i + j) >= a.at(i + j + 1)) {
                res += sum(j + 1);
                i += j;
                break;
            }
        }
    }

    cout << res << '\n';
    return 0;
}