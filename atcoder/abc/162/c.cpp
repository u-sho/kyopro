#include <bits/stdc++.h>
using ll = long long;

int gcd[202][202];

int main() {
    using std::cin;
    using std::cout;
    using std::endl;
    using std::min;
    using std::max;
    int k;
    cin >> k;

    ll sum = 0LL;

    for(int i=1; i<=k; i++)
        for(int j=1; j<=k; j++){
            gcd[min(i,j)][max(i,j)] = std::gcd(i,j);
        }
    
    for(int i=1; i<=k; i++){
        for(int j=1; j<=k; j++){
            for(int h=1; h<=k; h++){
                int g = gcd[min(i,j)][max(i,j)];
                sum += gcd[min(g,h)][max(g,h)];
            }
        }
    }

    cout << sum << endl;
    return 0;
}

