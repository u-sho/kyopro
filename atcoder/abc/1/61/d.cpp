#include <bits/stdc++.h>
long long jus[12]={
    1LL,
    10LL,
    100LL,
    1000LL,
    10000LL,

    100000LL,
    1000000LL,
    10000000LL,
    100000000LL,
    1000000000LL,

    10000000000LL,
    100000000000LL
};

long long runrun[100005];

long long digi_vol(int arr[12]){
    long long vol=0LL;
    for(int i=0; i<12; i++){
        vol+=(long long)arr[i]*jus[i];
    }
    return vol;
}

int main() {
    using namespace std;

    for(int p=1; p<=10000; p++){
        long long pun = runrun[p-1]; // pre runrun
        int digi[12]={
            pun%10,
            (pun/10LL)%10,
            (pun/100LL)%10,
            (pun/1000LL)%10,
            (pun/10000LL)%10,
            (pun/100000LL)%10,
            (pun/1000000LL)%10,
            (pun/10000000LL)%10,
            (pun/100000000LL)%10,
            (pun/1000000000LL)%10,
            (pun/10000000000LL)%10,
            (pun/100000000000LL)%10
        };
        int maxketa=0;
        for(int i=0; i<12; i++){
            if(digi[i]!=0)maxketa=i;
        }
        for(int i=0; i<11; i++){
            if(maxketa==i){
                digi[i]++;
                if(digi[i]==10){
                    digi[i]=0;
                    digi[i+1]=1;
                }
                for(int j=i-1; j>=0; j--)
                    digi[j]=max(0,digi[j+1]-1);

                break;
            }

            if(abs(digi[i]+1-digi[i+1])<=1 && digi[i]!=9){
                digi[i]++;
                for(int j=i-1; j>=0; j--)
                    digi[j]=max(0,digi[j+1]-1);

                break;
            }
        }

        runrun[p]=digi_vol(digi);
        // cout << p << ';' << runrun[p] << endl;
    }

    // ここまで定数

    int k; cin >> k;
    cout << runrun[k] << endl;

    return 0;
}