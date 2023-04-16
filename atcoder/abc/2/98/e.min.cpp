#include <atcoder/all>
atcoder::modint998244353 w, l, o, T[101][101], O[101][101];
int N, A, B, P, Q, t, i, p;
int main() {
    std::cin >> N >> A >> B >> P >> Q;
    T[0][A] = O[0][B] = 1;
    for (; t < N; w += l * T[++t][N])
        for (l = i = 0; i < N;) {
            for (p = P; p;) T[t + 1][std::min(i + p--, N)] += T[t][i] / P;
            for (l += o = O[t][i++]; p < Q;)
                O[t + 1][std::min(i + p++, N)] += o / Q;
        }
    std::cout << w.val();
}