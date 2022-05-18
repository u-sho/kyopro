#include <bits/stdc++.h>
int main() {
    using namespace std;
    int a,b,ans=-1;
    cin>>a>>b;
    for(int i=10; i<150'000; i++){
        if((i*8)/100==a && (i*10)/100==b){
            ans=i;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}