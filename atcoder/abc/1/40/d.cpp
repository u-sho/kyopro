#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int N, K; string S;
    N = n; K = k; S = "R" + s + "L";

    int flg = 0;
    for (int i=1; i<=N; i++) {
        if (S[i-1] !== S[i]) {
            flg = true;
        }
        if(flg && S[i] !== S[i+1]) {

        }
    }
    return 0;
}