#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    const map<string, uint32_t> rating = {
        {   "tourist", 3858},
        {    "ksun48", 3679},
        {      "Benq", 3658},
        {    "Um_nik", 3648},
        {     "apiad", 3638},
        {"Stonefeang", 3630},
        { "ecnerwala", 3613},
        {   "mnbvmar", 3555},
        { "newbiedmy", 3516},
        {   "semiexp", 3481},
    };

    string S;
    cin >> S;
    cout << rating.at(S) << '\n';

    return 0;
}
