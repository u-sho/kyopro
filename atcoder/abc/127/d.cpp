#include <bits/stdc++.h>

int main(void) {
    using namespace std;

    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (int &ai : A) cin >> ai;
    vector<pair<int, int>> CB(M);
    for (int i = 0; i < M; ++i) {
        int B, C;
        cin >> B >> C;
        CB.at(i) = make_pair(C, B);
    }

    sort(A.begin(), A.end());
    sort(CB.rbegin(), CB.rend());  // コストの降順
    auto b        = A.begin();
    long long ans = 0LL;
    for (int i = 0; i < M; ++i) {
        //以上の最初
        auto itl = lower_bound(b, A.end(), CB.at(i).first);
        if (itl == A.begin()) break;

        int it = itl - b;
        int df = min(CB.at(i).second, it);
        ans += (long long)df * (long long)CB.at(i).first;
        b = b + df;
    }
    ans += accumulate(b, A.end(), 0LL);

    cout << ans << endl;

    return 0;
}