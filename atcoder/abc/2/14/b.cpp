#include <iostream>

using namespace std;
using ui = unsigned;
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ui S, T;
    cin >> S >> T;

    ui count = 0;
    for (ui a = 0; a <= S; a++) {
        for (ui b = 0; a + b <= S; b++) {
            for (ui c = 0; a + b + c <= S; c++) {
                if (a * b * c <= T)
                    ++count;
                else
                    break;
            }
        }
    }

    cout << count << "\n";

    return 0;
}
