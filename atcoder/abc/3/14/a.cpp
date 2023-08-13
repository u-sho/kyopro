#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    const string pi =
        "3."
        "14159265358979323846264338327950288419716939937510"
        "58209749445923078164062862089986280348253421170679";

    uint N;
    cin >> N;
    cout << pi.substr(0, N + 2U);

    return 0;
}
