#include <iostream>

int main() {
    using std::cout;
    int m;
    std::cin >> m;
    if (m < 100) {
        cout << "00\n";
        return 0;
    }
    if (m < 1000) {
        cout << '0' << m / 100 << '\n';
        return 0;
    }
    if (m <= 5000) {
        cout << m / 100 << '\n';
        return 0;
    }
    if (m <= 30'000) {  //'
        cout << (m / 1000) + 50 << '\n';
        return 0;
    }
    if (m <= 70'000) {  //'
        cout << ((m / 1000) - 30) / 5 + 80 << '\n';
        return 0;
    }
    cout << "89\n";
    return 0;
}