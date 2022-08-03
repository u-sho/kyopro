#include <iostream>

using namespace std;
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    /*
    1 回目から 125 回目までは 4 問
    126 回目から 211 回目までは 6 問
    212 回目から 214 回目までは 8 問
    */
    if (n <= 125)
        cout << "4\n";
    else if (n <= 211)
        cout << "6\n";
    else if (n <= 214)
        cout << "8\n";

    return 0;
}
