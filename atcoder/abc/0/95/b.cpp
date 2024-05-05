#include <iostream>
using namespace std;
int N, X, m, M = 1e9, a;
main() {
    cin >> N >> X;
    for (a = N; N--; M = min(M, m), X -= m) cin >> m;
    cout << a + X / M;
}