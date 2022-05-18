#include <algorithm>
#include <iostream>
#include <string>

std::string deduplicate(std::string s) {
    std::sort(s.begin(), s.end());
    s.erase(std::unique(s.begin(), s.end()), s.end());
    return s;
}

int main() {
    using std::cin;
    using std::string;

    int n;
    cin >> n;
    string s;
    cin >> s;

    int ans = 0;
    for (int i = 1; i < n - 1; ++i) {
        string f = deduplicate(s.substr(0UL, i));
        string r = deduplicate(s.substr(i));

        int duplications = 0;
        for (char fc : f) {  // 𝑶(n * n/2 * n/2)
            if (r.find(fc) != string::npos) duplications++;
        }
        ans = std::max(ans, duplications);
    }

    std::cout << ans << "\n";
    return 0;
}