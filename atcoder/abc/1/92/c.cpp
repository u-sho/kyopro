#include <bits/stdc++.h>
using namespace std;
using ulli = unsigned long long;

/*
 g_1(314)=431,
 g_2(3021)=123,
 f(271)=721−127=594,

 a_0=N, a_{i+1}=f(a_i)
*/

ulli N, K;

vector<unsigned char> decimal_x;
vector<ulli> d = {1ULL,
                  10ULL,
                  100ULL,
                  1'000ULL,
                  10'000ULL,
                  100'000ULL,
                  1'000'000ULL,
                  10'000'000ULL,
                  100'000'000ULL,
                  1'000'000'000ULL,
                  10'000'000'000ULL,
                  100'000'000'000ULL};

void decimal(ulli x) {
    decimal_x.clear();
    while (x) {
        decimal_x.push_back((unsigned char)(x % 10ULL));
        x /= 10U;
    }
    return;
}

ulli f(ulli x) {
    decimal(x);
    // for (const ulli xi : decimal_x) cout << xi << " ";
    sort(decimal_x.begin(), decimal_x.end());
    ulli g1 = 0ULL;
    for (ulli i = 0LL; i < decimal_x.size(); i++) {
        g1 += decimal_x.at(i) * d.at(i);
    }
    // cout << g1 << endl;

    ulli g2 = 0UL;
    reverse(decimal_x.begin(), decimal_x.end());
    for (ulli i = 0LL; i < decimal_x.size(); i++) {
        g2 += decimal_x.at(i) * d.at(i);
    }
    // cout << g2 << endl;

    return ulli(g1 - g2);
}

ulli a(ulli n) {
    if (n == 0ULL) return N;
    return f(a(n - 1ULL));
}

int main(void) {
    cin >> N >> K;
    cout << a(K) << "\n";
    return 0;
}