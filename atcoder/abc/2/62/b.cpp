#include <bits/stdc++.h>
using namespace std;

using ui = unsigned;
#define REP1(i, n) for (ui i = 1UL; i <= (n); i++)

bool uv[102][102];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ui N, M;
    cin >> N >> M;
    REP1(i, M) {
        ui u, v;
        cin >> u >> v;
        uv[u][v] = uv[v][u] = true;
    }

    ui ans = 0U;
    for (ui a = 1; a < N; a++) {
        for (ui b = a + 1; b < N; b++) {
            if (!uv[a][b]) continue;
            for (ui c = b + 1; c <= N; c++) {
                if (!uv[b][c]) continue;
                if (!uv[c][a]) continue;
                ++ans;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
