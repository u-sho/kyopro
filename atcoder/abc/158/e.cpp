#include <bits/stdc++.h>
using ll = long long;

int main() {
    using namespace std;
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    vector<int> p(a), q(b), r(c);
    for (int i = 0; i < a; i++) cin >> p[i];
    for (int i = 0; i < b; i++) cin >> q[i];
    for (int i = 0; i < c; i++) cin >> r[i];

    sort(p.rbegin(), p.rend());
    sort(q.rbegin(), q.rend());
    sort(r.rbegin(), r.rend());

    int xi = 1, yi = 1;
    for (int i = 0; i < c; i++) {
        if (x < xi && y < yi) break;
        if (x < xi) {
            if (q[y - yi] < r[i]) {
                q[y - yi] = r[i];
                yi++;
            } else {
                break;
            }
            continue;
        }
        if (y < yi) {
            if (p[x - xi] < r[i]) {
                p[x - xi] = r[i];
                xi++;
            } else {
                break;
            }
            continue;
        }

        if (p[x - xi] < q[y - yi]) {
            if (p[x - xi] < r[i]) {
                p[x - xi] = r[i];
                xi++;
            } else {
                break;
            }
        } else {
            if (q[y - yi] < r[i]) {
                q[y - yi] = r[i];
                yi++;
            } else {
                break;
            }
        }
    }

    ll ans = 0LL;
    for (int i = 0; i < x; i++) ans += (long long)p[i];
    for (int i = 0; i < y; i++) ans += (long long)q[i];

    cout << ans << endl;
    // n
    return 0;
}