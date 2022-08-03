#include<iostream>
constexpr int N = 100005;
bool hikui[N];
int main(){
    using namespace std;
    int n,m;
    cin >> n  >> m;
    int h[N];
    for(int i=1; i<=n; i++) cin >> h[i];
    for(int i=0; i<m; i++) {
        int a,b;
        cin >> a >> b;
        if(h[a]<h[b])  hikui[a] = true;
        if(h[a]==h[b]) hikui[a] = hikui[b] = true;
        if(h[a]>h[b])  hikui[b] = true;
    }
    int ans = 0;
    for(int i=1; i<=n; i++){
        if(!hikui[i])ans++;
    }
    cout << ans << endl;
    return 0;
}