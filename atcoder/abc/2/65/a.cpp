#include <iostream>
using namespace std;

using ui = unsigned;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ui X, Y, N;
    cin >> X >> Y >> N;

    if (3 * X <= Y)
        cout << X * N << '\n';
    else
        cout << Y * (N / 3U) + X * (N % 3U) << '\n';

    return 0;
}
