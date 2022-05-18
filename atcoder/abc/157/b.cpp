#include <bits/stdc++.h>
const std::string ans[2] = { "No\n", "Yes\n" };
int main() {
    using namespace std;
    int a[3][3];
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            cin >> a[i][j];

    int n,b;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> b;
        for(int i=0; i<3; i++)
            for(int j=0; j<3; j++)
                if(a[i][j]==b)a[i][j]=-1;
    }

    bool isBingo=false;
    // tate
    for(int i=0; i<3; i++)
        if(a[i][0]==-1 && a[i][1]==-1 && a[i][2]==-1)isBingo = true;
    // yoko
    for(int i=0; i<3; i++)
        if(a[0][i]==-1 && a[1][i]==-1 && a[2][i]==-1)isBingo = true;
    // naname
    if(a[0][0]==-1 && a[1][1]==-1 && a[2][2]==-1)isBingo=true;
    if(a[0][2]==-1 && a[1][1]==-1 && a[2][0]==-1)isBingo=true;

    cout << ans[isBingo] << endl;
    
    return 0;
}
