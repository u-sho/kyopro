#include <iostream>
using namespace std;
int A, B, C, X, Y;
main() {
    cin >> A >> B >> C >> X >> Y;
    cout << min(min(A * X + B * Y, 2 * C * max(X, Y)),
                X > Y ? 2 * C * Y + A * (X - Y) : 2 * C * X + B * (Y - X));
}