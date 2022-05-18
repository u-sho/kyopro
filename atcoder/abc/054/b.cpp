#include <bits/stdc++.h>
int main(){
    using namespace std;
    int n,m;
    cin>>n>>m;
    string a[n],b[m];
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<m;i++)cin>>b[i];

    bool ans=false;
    for(int i=0; i<=n-m; i++){
        for(int j=0; j<=n-m; j++){ //左上i,j
            for(int k=0; k<m; k++){
                if (a[i+k].substr(j,m)!=b[k]) break;
                if (k==m-1)ans=true;
            }
        }
    }

    cout << (ans ? "Yes\n" : "No");
    return 0;
}