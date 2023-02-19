#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    uint N, M;
    cin>>N>>M;
    vector<uint> A(N);
    for (uint &Ai : A) cin >> Ai;
    vector<uint> B(M);
    for (uint &Bi : B) cin >> Bi;

    uint sunuke_score = 0;
    for(const uint Bi: B){
        sunuke_score += A.at(Bi-1);
    }

    cout << sunuke_score << '\n';

    return 0;
}
