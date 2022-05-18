#include <bits/stdc++.h>

int main() {
    using namespace std;
    int n,m;
    cin >> n >> m;
    int ans[n] = {1,};
    bool checked[n];
    if(n==1)ans[0]=0;
    fill(checked, checked+n, false);
    bool isExsist = true;
    for(int i=0; i<m; i++){
        int s,c;
        cin >> s >> c;
        if((s==1 && c==0 && n!=1) || (checked[s-1] && ans[s-1]!=c)) {
            isExsist = false;
            break;
        }
        ans[s-1]=c;
        checked[s-1]=true;
    }
    if(!isExsist)cout << "-1\n";
    else {
        for(int i=0; i<n; i++){
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}
