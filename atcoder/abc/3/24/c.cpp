#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (size_t i = 0UL; i < (n); i++)

int main() {
    uint N;
    string Td;
    cin >> N >> Td;
    vector<string> S(N);
    for (string &Si : S) cin >> Si;

    vector<size_t> ans;

    const auto t = Td.size();
    REP(i, N) {
        const auto s = S[i].size();

        // T' は，T と等しい．
        // T' は，T のある1文字を別の英小文字に変更して得られる文字列である．
        if (s == t) {
            uint changed = 0;
            REP(j, s) {
                if (S[i][j] != Td[j]) ++changed;
                if (changed > 1U) break;
            }
            if (changed <= 1U) ans.push_back(i + 1);
        }

        // T' は，T
        // のいずれか1つの位置に英小文字を1つ挿入して得られる文字列である．
        if (s + 1UL == t) {
            uint inserted = 0;
            REP(j, s) {
                if (S[i][j] != Td[j + inserted]) {
                    ++inserted;
                    --j;
                }
                if (inserted > 1U) break;
            }
            if (inserted <= 1U) ans.push_back(i + 1);
        }

        // T' は，T からある1文字を削除して得られる文字列である．
        if (s == t + 1UL) {
            uint deleted = 0;
            for (size_t j = 0; j + deleted < s; j++) {
                if (S[i][j + deleted] != Td[j]) {
                    ++deleted;
                    --j;
                }
                if (deleted > 1U) break;
            }
            if (deleted <= 1U) ans.push_back(i + 1);
        }
    }

    const uint K = ans.size();
    cout << K << "\n";
    REP(i, K) { cout << ans[i] << (i + 1 == K ? "" : " "); }
    cout << endl;

    return 0;
}
