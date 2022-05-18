#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::string;
using std::vector;
using Grid = vector<string>;

constexpr char WALL   = '.';
constexpr char PASSED = '#';

int main() {
    short H, W;
    cin >> H >> W;
    Grid A(H);
    for (string &s : A) cin >> s;

    short pass_area_count = 1;
    for (const string &s : A) {
        for (int i = 0; i < W; ++i) {
            if (s.at(i) == PASSED) pass_area_count++;
        }
    }

    if (pass_area_count > H + W)
        cout << "Impossible\n";
    else
        cout << "Possible\n";

    return 0;
}