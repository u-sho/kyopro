#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
const long long MOD=2019;

int main(void){
    long long L,R;
    cin>>L>>R;

    if(L/MOD < R/MOD){
        cout<<"0\n";
        return 0;
    }

    L%=MOD;
    R%=MOD;

    int ans=MOD;
    int pro=0;
    for(int i=L; i<=R; i++){
        for(int j=i+1; j<=R; j++){
            pro=(i*j)%MOD;
            if(pro<ans){
                ans=pro;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}