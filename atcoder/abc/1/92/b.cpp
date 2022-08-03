#include <iostream>
#include <string>
int main() {
    std::string s;
    std::cin >> s;

    bool is_difficult = true;
    for (int i = 0; i < s.length() && is_difficult; i++) {
        if ((i & 1) == 0 && 'A' <= s[i] && s[i] <= 'Z') is_difficult = false;
        if (i & 1 && 'a' <= s[i] && s[i] <= 'z') is_difficult = false;
    }

    std::cout << (is_difficult ? "Yes\n" : "No\n");
    return 0;
}