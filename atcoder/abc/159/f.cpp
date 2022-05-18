#include <bits/stdc++.h>
using ll = long long;

constexpr ll MOD = 998'244'353;

int main() {
    using namespace std;
    int N, S;
    cin >> N >> S;
    int A[N];
    for (int i = 0; i < N; i++) cin >> A[i];

    int p_sum[N+1] = {0LL};
    p_sum = p_sum + 1;
    p_sum[0] = A[0];
    for (int i = 1; i < N; i++) {
        p_sum[i] = p_sum[i - 1] + A[i];
    }

    for (int i = 0; i < N-1; i++) {
        for (int j = i+1; j < N; j++) {
            int sum = p_sum[j] - p_sum[i-1];
            if (sum != S) continue;
            
        }
    }
    return 0;
}