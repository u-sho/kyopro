#include <algorithm>
#include <iostream>
#include <string>
int main() {
    using namespace std;
    int a, b;
    cin >> a >> b;
    if (a == b) {
        cout << a + b << endl;
        return 0;
    }
    int ans = 2 * max(a, b) - 1;
    cout << ans << endl;

    return 0;
}