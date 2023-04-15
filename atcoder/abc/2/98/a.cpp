#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (unsigned i = 0U; i < (n); i++)

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    unsigned N;
    cin >> N;

    bool get_Good = false;
    bool get_Poor = false;
    REP(i, N) {
        char Si;
        cin >> Si;
        get_Good |= (Si == 'o');
        get_Poor |= (Si == 'x');
    }

    bool is_passed = get_Good & !get_Poor;
    cout << (is_passed ? "Yes\n" : "No\n");

    return 0;
}
