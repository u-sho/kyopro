#include <bits/stdc++.h>
using namespace std;

template <typename T1, typename T2>
std::istream &operator>>(std::istream &is, std::pair<T1, T2> &p) {
    is >> p.first >> p.second;
    return is;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    uint N;
    cin >> N;
    string S;
    cin >> S;
    uint Q;
    cin >> Q;
    vector<pair<uint, pair<uint, char>>> txc(Q);
    for (auto &txci : txc) cin >> txci;

    int isCapitalized = -1;
    int isLowerized   = -1;
    for (uint i = 0; i < Q; i++) {
        const auto &[t, xc] = txc[i];
        if (t == 1) S[xc.first - 1] = xc.second;
        if (t == 2) isLowerized = i;
        if (t == 3) isCapitalized = i;
    }

    if (isCapitalized == isLowerized) {
        cout << S << "\n";
        return 0;
    }
    if (isLowerized < isCapitalized) {
        for (char &Si : S) Si = toupper(Si);
        for (uint i = isCapitalized; i < Q; i++) {
            const auto &[t, xc] = txc[i];
            if (t == 1) S[xc.first - 1] = xc.second;
        }
    } else {
        for (char &Si : S) Si = tolower(Si);
        for (uint i = isLowerized; i < Q; i++) {
            const auto &[t, xc] = txc[i];
            if (t == 1) S[xc.first - 1] = xc.second;
        }
    }

    cout << S << "\n";

    return 0;
}
