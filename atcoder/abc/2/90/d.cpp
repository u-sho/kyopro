#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    vector<bool> sunuke_marks(1000000009);

    int T;
    cin >> T;
    while(T--){
        uint64_t N, D, K;
        cin >> N >> D >> K;

        // 愚直
        // if (K < 1000) {
        //     sunuke_marks.assign(N+1, false);
        //     sunuke_marks.at(0) = true; // 1番目に印をつけた
        //     uint last_marked = 0;
        //     for(uint i=2; i<=K; i++){
        //         // 手順 i
        //         uint x = (last_marked+D) % N;

        //         // 手順 ii
        //         while(sunuke_marks.at(x)) {
        //             x = (x+1) % N;
        //         }

        //         // 手順 iii
        //         sunuke_marks.at(x) = true; // i番目に印をつけた
        //         last_marked = x;
        //     }
        //     cout << last_marked << '\n';
        //     continue;
        // }

        // D と N が互いに素なら、手順ii に入らない
        uint64_t gcdDN = gcd(D, N);
        if (gcdDN == 0) {
            cout << (((K-1)*D)%N) << '\n';
            continue;
        }

        // D と N が共通因数をもつとき
        else {
            // 手順i, iiiを繰り返す
            uint64_t kaisuu = N / gcdDN;
            if (K<=kaisuu){
                cout << (((K-1)*D)%N) << '\n';
                continue;
            }

            uint64_t last_marked = K / kaisuu;
            K %= kaisuu;
            if (K == 0) {
                cout << ((last_marked - 1ULL) + (kaisuu-1ULL)*D)%N << '\n';
            } else {
                cout << ((last_marked + (K-1)*D)%N) << '\n';
            }
        }
    }

    return 0;
}