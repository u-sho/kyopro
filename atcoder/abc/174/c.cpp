#include <iostream>
using namespace std;
using ulli = unsigned long long;

int main() {
    int K;
    cin >> K;

    int sevens = 7;
    for (int i = 1; i < 2'000'000; ++i) {
        if (sevens % K == 0) {
            cout << i << '\n';
            return 0;
        }
        sevens *= 10UL;
        sevens += 7UL;
        sevens %= K;
    }

    cout << "-1\n";
    return 0;
}
