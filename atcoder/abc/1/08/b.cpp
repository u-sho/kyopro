#include <iostream>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int x3 = y1 - y2 + x2;
    int y3 = x2 - x1 + y2;
    int x4 = y2 - y3 + x3;
    int y4 = x3 - x2 + y3;

    cout << x3 << " " << y3 << " " << x4 << " " << y4 << "\n";

    return 0;
}
