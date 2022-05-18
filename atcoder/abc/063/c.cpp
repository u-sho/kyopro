#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> s(n);
    for(int i=0; i<n; ++i)cin>>s[i];

    sort(s.begin(),s.end());
    int sum = accumulate(s.begin(),s.end(),0);

    if(sum%10) {
        cout << sum << endl;
        return 0;
    }

    for (int i=0; i<n; ++i) {
        if(s[i]%10){
            cout << sum-s[i] << endl;
            return 0;
        }
    }

    cout << 0 << endl;
    return 0;
}