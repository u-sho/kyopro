#include <bits/stdc++.h>
struct drug {
    int a,b,c;
    drug(int a,int b,int c) : a(a),b(b),c(c) {}
};
using Drugs = std::vector<drug>;

int main(){
    using namespace std;
    int n,ma,mb;
    cin>>n>>ma>>mb;

    Drugs ds(n);
    int ans = 1000;
    for(int i=0; i<n; i++){
        int a,b,c;
        cin >> a >> b >> c;
        ds[i] = drug(a%ma,b%mb,c);
        if (ma*b==mb*a) ans = min(c,ans);
    }

    // 2個以上の場合について調べる
    




    return 0;
}