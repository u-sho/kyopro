#include <bits/stdc++.h>
using namespace std;

using ui = unsigned;
using lli = long long;
using ulli = unsigned long long;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ui N;
    ulli P, Q, R;
    cin >> N >> P >> Q >> R;
    vector<ulli> A(N);
    for (ulli &Ai : A) cin >> Ai;

    ui x = 0, y = 1;
    ulli p = A[0];
    for (; x < N - 3; x++) {
        // cout << "x: " << x << "\n";
        if (x >= y) {
            y = x + 1;
            p = A[x];
        }
        while (y < N - 2 && p + A[y] <= P) {
            // cout << "x: " << x << ", y: " << y << "\n";
            p += A[y];
            y++;
        }
        if (p != P) {
            p -= A[x];
            continue;
        }

        // p equals P. x, y are fixed.
        ui z = y + 1;
        ulli q = A[y];
        while (z < N - 1 && q + A[z] <= Q) {
            // cout << "x: " << x << ", y: " << y << ", z: " << z << "\n";
            q += A[z];
            z++;
        }
        if (q != Q) {
            p -= A[x];
            continue;
        }

        // (p,q) equals (P,Q). x, y, z are fixed.
        ui w = z + 1;
        ulli r = A[z];
        while (w < N && r + A[w] <= R) {
            // cout << "x: " << x << ", y: " << y << ", z: " << z << ", w: " <<
            // w
            //      << "\n";
            r += A[w];
            w++;
        }
        if (r != R) {
            p -= A[x];
            continue;
        }

        // (p,q,r) equals (P,Q,R).
        cout << "Yes\n";
        return 0;
    }

    cout << "No\n";
    return 0;
}
