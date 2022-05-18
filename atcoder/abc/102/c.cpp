#include <bits/stdc++.h>
using namespace std;
using lli  = long long;
using ulli = unsigned long long;

int main() {
    size_t N;
    cin >> N;
    vector<int> A(N);
    for (int &Ai : A) cin >> Ai;

    for (int i = 0; i < N; ++i) {
        A.at(i) -= i + 1;
    }

    lli b   = accumulate(A.begin(), A.end(), 0LL) / (lli)N;
    lli be  = b + 1LL;
    lli bee = b - 1LL;

    lli b_sad   = 0LL;
    lli be_sad  = 0LL;
    lli bee_sad = 0LL;
    for (size_t i = 0uL; i < N; ++i) {
        b_sad += abs(A.at(i) - b);
        be_sad += abs(A.at(i) - be);
        bee_sad += abs(A.at(i) - bee);
    }

    cout << min(b_sad, min(be_sad, bee_sad)) << '\n';

    return 0;
}
