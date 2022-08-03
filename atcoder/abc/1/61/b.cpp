#include <bits/stdc++.h>
const std::string ans[2] = { "No\n", "Yes\n" };
int main() {
    using namespace std;
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    long long sum=0LL;
    for(int i=0;i<n;i++){
        cin >> a[i];
        sum += a[i];
    }
    sort(a.rbegin(),a.rend());
    double border = sum*0.2500/(double)m;
    int selected = 0;
    for(int i=0; i<n; i++){
        if(border>a[i])break;
        selected=i+1;
    }

    cout << ans[selected>=m];
    return 0;
}