#include <bits/stdc++.h>
using namespace std;
using V  = vector<int>;
using VV = vector<V>;

bool enable(const size_t M, const int X, const VV A);
bool enable_with(const size_t M, const int X, const VV A,
                 const vector<bool> use);
int calc_min_sum(const size_t N, const size_t M, const int X, const V C,
                 const VV A);

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    size_t N, M;  // <= 12, N:参考書の数，M:アルゴリズムの数
    int X;        // <= 1e5, X:理解度の目標
    cin >> N >> M >> X;

    V C(N);   // <= 1e5, Ci:参考書の価格
    VV A(N);  // <= 1e5, Aij:上昇する理解度
    for (size_t i = 0UL; i < N; i++) {
        cin >> C[i];
        A[i].resize(M);
        for (int &Aij : A[i]) cin >> Aij;
    }

    // 高橋くんが目標を達成することが可能か判定
    if (!enable(M, X, A)) {
        cout << "-1\n";
        return 0;
    }

    // 可能な場合は目標を達成するのに必要な金額の最小値を計算
    cout << calc_min_sum(N, M, X, C, A) << "\n";

    return 0;
}

bool enable(const size_t M, const int X, const VV A) {
    V rikaido(M, 0);
    for (const auto &Ai : A) {
        for (size_t j = 0UL; j < M; j++) {
            rikaido[j] += Ai.at(j);
        }
    }

    for (const int r : rikaido) {
        if (r < X) return false;
    }
    return true;
}

bool enable_with(const size_t M, const int X, const VV A,
                 const vector<bool> use) {
    V rikaido(M, 0);
    for (size_t i = 0UL; i < A.size(); ++i) {
        if (!use.at(i)) continue;
        for (size_t j = 0UL; j < M; j++) {
            rikaido[j] += A[i].at(j);
        }
    }

    for (const int r : rikaido) {
        if (r < X) return false;
    }
    return true;
}

int calc_min_sum(const size_t N, const size_t M, const int X, const V C,
                 const VV A) {
    // 本Ciを「買う/買わない」で全探索:
    // 判定に 𝑶(NM) かかるので 𝑶(NM * 2^N)

    int min_sum = INT_MAX;
    for (unsigned long u = 0UL; u < (1UL << N); ++u) {
        vector<bool> use(N);
        int sum = 0;
        for (size_t i = 0UL; i < N; i++) {
            use[i] = (u & (1 << i));
            if (use[i]) sum += C.at(i);
        }
        if (enable_with(M, X, A, use)) {
            min_sum = min(min_sum, sum);
        }
    }

    return min_sum;
}
