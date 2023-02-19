#include<bits/stdc++.h>

std::vector<bool> numbers_in_A0K(300005);

int main(){
    using namespace std;
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    uint N, K;
    cin >> N >> K;
    vector<uint> A(N);
    for (uint &Ai : A) cin >> Ai;

    for (const uint& Ai: A){
        if (Ai < K) numbers_in_A0K.at(Ai) = true;
    }

    for (uint i=0; i<K; i++){
        if (!numbers_in_A0K.at(i)){
            cout << i << '\n';
            return 0;
        }
    }
    cout << K << '\n';
    return 0;
}