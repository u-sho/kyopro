#include <iostream>
#include <vector>

// 0 padding
unsigned P;
unsigned squares[8];

int main(void) {
    using namespace std;

    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    size_t N;
    cin >> N;
    vector<unsigned> A(N);  // GCC拡張
    for (unsigned &Ai : A) cin >> Ai;

    for (const unsigned Ai : A) {
        squares[0]++;
        for (int x = 3; x >= 0; x--) {
            squares[x + Ai] += squares[x];
            squares[x] = 0u;
        }
    }

    for (unsigned i = 4u; i < 8u; i++) {
        P += squares[i];
    }
    cout << P << "\n";

    return 0;
}