#include <bits/stdc++.h>
using ll = long long;

int main() {
    using namespace std;
    int n;
    cin >> n;
    vector<int>x(n);
    for(int i=0; i<n; i++)cin>>x[i];

    int ans=1'000'000'000; //'
    for(int i=1; i<=100; i++){
        // int sum = accumulate(x.begin(),x.end(),[](int acc, int j){
        //     return acc + (i-j)*(i-j);
        // });
        int sum =0;
        for(int j=0; j<n; j++) sum += (i-x[j])*(i-x[j]);

        ans = min(ans, sum);
    }

    cout << ans << endl;

    return 0;
}
