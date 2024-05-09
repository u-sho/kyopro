#include <iostream>
using namespace std;
#include <atcoder/segtree>
using atcoder::segtree;

uint umax(uint a, uint b) { return max(a, b); }
uint UMIN() { return 0U; }

int main(void) {
    uint N, Q;
    cin >> N >> Q;

    segtree<uint, umax, UMIN> A(N + 1);
    while (Q--) {
        char c;
        cin >> c;
        if (c == '1') {
            uint pos, x;
            cin >> pos >> x;
            A.set(pos, x);
        }
        if (c == '2') {
            uint l, r;
            cin >> l >> r;
            cout << A.prod(l, r) << '\n';
        }
    }
    return 0;
}