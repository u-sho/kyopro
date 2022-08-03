#include <iostream>
#include <vector>
using std::cin;
using std::cout;

int main() {
    int n;
    cin >> n;
    std::vector<int> h(n);
    for (int &hi : h) cin >> hi;

    for (int i = n - 1; i; --i) {
        if (h.at(i) < h.at(i - 1)) {
            h.at(i - 1)--;
            if (h.at(i) < h.at(i - 1)) {
                cout << "No\n";
                return 0;
            }
        }
    }
    cout << "Yes\n";

    return 0;
}