#include <bits/stdc++.h>
int main() {
    using namespace std;
    int h, a;
    cin >> h >> a;
    cout << h / a + ((h % a) ? 1 : 0) << endl;
    return 0;
}