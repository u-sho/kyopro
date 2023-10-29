#include <iostream>
using namespace std;
int main() {
    uint X, Y;
    cin >> X >> Y;
    if (X <= Y && Y - X <= 2) cout << "Yes\n";
    else if (X > Y && X - Y <= 3) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}