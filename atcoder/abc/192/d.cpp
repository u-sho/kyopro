#include <bits/stdc++.h>
using namespace std;
using us   = unsigned short;
using lli  = long long;
using ulli = unsigned long long;

deque<us> vecX, n_ary_M;

void make_M_n_ary(ulli M, const ulli n) {
    n_ary_M.clear();
    while (M) {
        n_ary_M.push_front(us(M % n));
        M /= n;
    }
    return;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string X;
    cin >> X;
    ulli M;
    cin >> M;

    char d = char(0);
    for (const char Xi : X) {
        char di = Xi - '0';
        vecX.push_back(us(di));
        d = max(di, d);
    }

    int ans = 0;
    for (us i = us(d + char(1)); i < UCHAR_MAX; i++) {
        make_M_n_ary(M, i);
        if (vecX <= n_ary_M)
            ++ans;
        else
            break;
    }

    cout << ans << "\n";

    return 0;
}
