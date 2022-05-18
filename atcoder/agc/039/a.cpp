#include <string>
#include <iostream>

using namespace std;

long long Solve(string S, long long K) {
    const int LENG = S.length();
    if (LENG == 1) return K / 2;

    if (LENG == 2) {
        if (S[0] == S[1]) return K;
        return 0LL;
    }

    long long ans = 0LL;
    for(int i=0; i<LENG-1; i++) {
        if (S[i] == S[i+1]) {
            ans++;
            if (i != LENG-2) {
                if (S[i] == S[i+2]) i++;
            }
        }
    }
    if (K==1) return ans;
    if (S[0] != S[LENG-1]) return ans*K;

    long long ans_composition=0LL;
    S = S + S;
    for(int i=0; i<2*LENG-1; i++) {
        if (S[i] == S[i+1]) {
            ans_composition++;
            if (1 != 2*LENG-2) {
                if (S[i] == S[i+2]) i++;
            }
        }
    }
    return ans*K + (ans_composition-2*ans)*(K-1);
}

int main(){
    string S;
    cin >> S;
    long long K;
    cin >> K;
    cout << Solve(S,K) << endl;
    return 0;
}