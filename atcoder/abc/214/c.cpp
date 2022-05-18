#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    using namespace std;
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> S(N), T(N);
    for (int &Si : S) cin >> Si;
    for (int &Ti : T) cin >> Ti;

    if (N == 1) {
        cout << T[0] << "\n";
        return 0;
    }

    do {
        T[0] = min(T[N - 1] + S[N - 1], T[0]);
        for (int i = 1; i < N; i++) T[i] = min(T[i - 1] + S[i - 1], T[i]);
    } while (T[N - 1] + S[N - 1] < T[0]);

    for (const int &Ti : T) cout << Ti << "\n";
    return 0;
}
