#include <bits/stdc++.h>
using namespace std;

int main() {
    size_t N;
    cin >> N;
    vector<int> A(N);
    for (int &Ai : A) cin >> Ai;

    while (true) {
        sort(A.begin(), A.end());
        A.erase(unique(A.begin(), A.end()), A.end());

        if (A.size() == 1uL) {
            cout << A.at(0) << '\n';
            return 0;
        }

        for (size_t i = 1uL; i < A.size(); ++i) {
            A.at(i) %= A.at(0);
            if (A.at(i) == 0) {
                A.erase(A.begin() + i);
                --i;
            }
        }
    }

    return 0;
}
