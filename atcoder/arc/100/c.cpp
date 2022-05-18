#include <bits/stdc++.h>
using namespace std;

int main(){
    long long N;
    cin>>N;
    long long A[N];
    for(int i=0; i<N; i++){
        cin >> A[i];
        A[i] -= (long long)(i+1LL);
    }
    long long sum =0LL;
    for(int i=0; i<N; i++){
        sum += A[i];
    }
    long long ave = (long long)round( (long double)sum/(long double)N );
    long long ans1 =0LL, ans2=0LL, ans3=0LL,ans4=0LL,ans5=0LL;
    for(int i=0; i<N; i++){
        ans1 += abs(A[i]-ave);
        ans2 += abs(A[i]-ave-1LL);
        ans3 += abs(A[i]-ave+1LL);
        ans4 += abs(A[i]-ave-2LL);
        ans5 += abs(A[i]-ave+2LL);
    }

    cout<< min( min( min(ans1,ans2),min(ans3,ans4) ),ans5 ) << endl;
    return 0;
}
