#include <iostream>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // ReLU(x) = x (x>=0), 0(x<0)
    int x;
    cin >> x;
    cout << max(x, 0) << "\n";

    return 0;
}
