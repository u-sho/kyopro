#include <iostream>
using namespace std;
int main() {
    unsigned N;
    cin >> N;
    for (unsigned x = 0U; x <= N; x++)
        for (unsigned y = 0U; x + y <= N; y++)
            for (unsigned z = 0U; x + y + z <= N; z++) {
                cout << x << ' ' << y << ' ' << z << '\n';
            }
    return 0;
}