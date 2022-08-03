#include <iostream>
#include <vector>
int main() {
    using namespace std;
    int n;
    cin >> n;

    vector<int> h(n);
    for (int &hi : h) cin >> hi;

    int h_max = 0;
    int ans   = 0;
    for (const int &hi : h) {
        if (h_max <= hi) {
            h_max = hi;
            ++ans;
        }
    }

    cout << ans << endl;
    return 0;
}