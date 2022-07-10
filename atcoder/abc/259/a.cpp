#include <iostream>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, M, X, T, D;
    cin >> N >> M >> X >> T >> D;

    if (M < X) {
        cout << M * D + (T - X * D) << endl;
        return 0;
    }

    cout << T << endl;
    return 0;
}
