#include <bits/stdc++.h>

const std::string ans[2]  = {"NO\n", "YES\n"};
const std::string keyence = "keyence";

int main() {
    std::string S;
    std::cin >> S;

    std::size_t n = S.length();

    if (n == 7) {
        std::cout << ans[(S == keyence)];
        return 0;
    }

    for (int i = 0; i <= 7; ++i) {
        std::string c_keyence = S.substr(0, i) + S.substr(i + n - 7, 7 - i);
        if (c_keyence == keyence) {
            std::cout << ans[1];
            return 0;
        }
    }

    std::cout << ans[0];
    return 0;
}