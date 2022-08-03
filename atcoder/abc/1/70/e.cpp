#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using std::make_pair;
using std::pair;

using std::max;
using std::min;
using std::sort;

using std::cin;
using std::cout;

using std::vector;

int main() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> yochien(200'001);
    vector<pair<int, int>> enji(n + 1);
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        enji.at(i + 1).first  = a;  // rate
        enji.at(i + 1).second = b;  // yochien
        yochien.at(b).push_back(a);
        sort(yochien.at(b).begin(), yochien.at(b).end());
    }

    vector<int> byodosa;
    for (int i = 1; i < 200'001; ++i) {
        if (!yochien.at(i).empty()) byodosa.push_back(yochien.at(i).back());
    }
    sort(byodosa.begin(), byodosa.end());

    vector<int> ans;
    for (int i = 0; i < q; ++i) {
        int c, d;
        cin >> c >> d;
        int a             = enji.at(c).first;   // rate
        int b             = enji.at(c).second;  // yochien before
        enji.at(c).second = d;                  // after yochien

        // for (const int t : yochien.at(b)) {
        //     cout << t << " ";
        // }
        // cout << std::endl;

        auto it =
            std::lower_bound(yochien.at(b).begin(), yochien.at(b).end(), a);
        // cout << "here1 " << a << std::endl;
        yochien.at(b).erase(it);  // fixme
        if (yochien.at(b).empty()) {
            auto b_it = std::lower_bound(byodosa.begin(), byodosa.end(), a);
            byodosa.erase(b_it);  // fixme
        } else if (a > yochien.at(b).back()) {
            auto b_it = std::lower_bound(byodosa.begin(), byodosa.end(), a);
            byodosa.at(b_it - byodosa.begin()) = yochien.at(b).back();
            sort(byodosa.begin(), byodosa.end());
        }

        // cout << "here2\n";
        if (yochien.at(d).empty()) {
            byodosa.push_back(a);
            sort(byodosa.begin(), byodosa.end());
        }
        if (yochien.at(d).back() < a) {
            auto b_it = std::lower_bound(byodosa.begin(), byodosa.end(),
                                         yochien.at(d).back());
            byodosa.at(b_it - byodosa.begin()) = a;
            sort(byodosa.begin(), byodosa.end());
        }
        yochien.at(d).push_back(a);
        sort(yochien.at(d).begin(), yochien.at(d).end());

        // for (const int t : yochien.at(b)) {
        //     cout << t << " ";
        // }
        // cout << std::endl;

        ans.push_back(byodosa.front());
    }

    for (const int e : ans) cout << e << '\n';
    return 0;
}