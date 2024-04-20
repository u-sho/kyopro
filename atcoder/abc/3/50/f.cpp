#include <bits/stdc++.h>
using namespace std;

string S;

/** parens[i]: S[i]==')' に対応する '(' の位置 または その逆 */
vector<uint> parens;

/** f(l,r,depth): depthの偶奇に応じ S[l,r] を（順に or 反転して）出力する */
void f(uint l, uint r, bool is_odd_depth = false) {
    if (is_odd_depth) {
        for (uint i = r; i >= l; i--) {
            if (S[i] == ')') {
                f(parens[i] + 1U, i - 1U, false);
                i = parens[i];
            } else {
                cout << S[i];
            }
        }
        return;
    }

    for (uint i = l; i <= r; i++) {
        if (S[i] == '(') {
            f(i + 1U, parens[i] - 1U, true);
            i = parens[i];
        } else {
            cout << S[i];
        }
    }
    return;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> S;
    const uint n = S.length();

    uint depth = 0;
    stack<uint> lparen;
    parens.resize(n);
    for (uint i = 0; i < n; i++) {
        if (S[i] == '(') {
            ++depth;
            lparen.push(i);
        } else if (S[i] == ')') {
            --depth;
            parens[i] = lparen.top();
            lparen.pop();
            parens[parens[i]] = i;
        } else if (depth & 1U) {
            if (S[i] <= 'Z') S[i] += 'a' - 'A';
            else S[i] -= 'a' - 'A';
        }
    }

    f(0U, n - 1U);

    return 0;
}
