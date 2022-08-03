#include <bits/stdc++.h>
using namespace std;
using uli = unsigned long;

vector<pair<uli, bool>> primes_used;

void Sieve() {  // 1e3以下の素数を列挙
    const size_t max_Ai      = 1'000'006UL;
    const size_t sqrt_max_Ai = 1003UL;

    vector<bool> is_prime(max_Ai, true);
    is_prime.at(0) = false;
    is_prime.at(1) = false;

    for (size_t p = 2UL; p < sqrt_max_Ai; p++) {
        if (!is_prime.at(p)) continue;
        primes_used.push_back(make_pair(p, false));
        for (size_t np = p * p; np < max_Ai; np += p) is_prime.at(np) = false;
    }
}

string Solve(vector<uli> &A) {
    // GCD(A_1, ... , A_N) == 1 ? "set/pair-wise" : "not coprime"
    uli gcd_all = A.at(0);
    for (const uli Ai : A) gcd_all = gcd(gcd_all, Ai);
    if (gcd_all > 1UL) return "not coprime\n";

    // 1<=i<j<=N, GCD(A_i, A_j) == 1 ? "pairwise" : "setwise"
    // 各要素に同じ素因子が含まれるか ? "setwise" : "pairwise"
    Sieve();  // primes_used に 1e3 以下の素数をセット
    for (uli Ai : A) {
        if (Ai == 1UL) continue;
        for (pair<uli, bool> &p : primes_used) {
            if (Ai < 1000) break;
            if (Ai % p.first == 0UL) {
                if (p.second) return "setwise coprime\n";
                p.second = true;
            }
            while (Ai % p.first == 0UL) Ai /= p.first;
        }
        // 1e3 より大きな素因数をもつ場合
        if (Ai > 1UL) primes_used.push_back(make_pair(Ai, true));
    }

    return "pairwise coprime\n";
}

int main() {
    // input
    size_t N;
    cin >> N;
    vector<uli> A(N);
    for (uli &Ai : A) cin >> Ai;

    // output
    cout << Solve(A);

    return 0;
}
