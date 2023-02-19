#include<bits/stdc++.h>
using namespace std;

int main(void){
    uint N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    for (uint i=0; i<N; i++){
        if (S.at(i)=='o' && K > 0) {
            cout << 'o';
            --K;
        } else {
            cout << 'x';
        }
    }
    cout << '\n';

    return 0;
}