#include <bits/stdc++.h>
using namespace std;
int main() {
    const vector<string> DAYS = {"Monday", "Tuesday", "Wednesday", "Thursday",
                                 "Friday"};
    string S;
    cin >> S;
    int it = find(DAYS.begin(), DAYS.end(), S) - DAYS.begin();
    cout << 5 - it << endl;
    return 0;
}