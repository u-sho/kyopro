#include <bits/stdc++.h>
using namespace std;

#define ALL(v) (v).begin(), (v).end()

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &v) {
    for (uint i = 0; i < v.size(); i++) {
        os << v[i] << (i + 1 != v.size() ? " " : "");  // 空白区切り
    }
    return os;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    uint N;
    cin >> N;
    vector<uint> C(N);
    vector<vector<uint>> A(N);
    for (uint i = 0; i < N; i++) {
        cin >> C[i];
        A[i].resize(C[i]);
        for (uint &Aij : A[i]) cin >> Aij;
    }
    uint X;
    cin >> X;

    vector<pair<uint, uint>> Cperson_betX;
    for (uint i = 0; i < N; i++) {
        for (const uint &Aij : A[i]) {
            if (Aij == X) Cperson_betX.push_back({C[i], i});
        }
    }

    auto min_Ci_it = min_element(ALL(Cperson_betX));
    vector<uint> B;
    for (const auto &[Ci, pi] : Cperson_betX) {
        if ((*min_Ci_it).first == Ci) B.push_back(pi + 1);
    }
    uint K = B.size();

    cout << K << '\n';
    cout << B << '\n';

    return 0;
}
