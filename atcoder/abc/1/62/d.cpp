#include <bits/stdc++.h>
using ll = long long;

bool ba[4003];

int main() {
    using std::cin;
    using std::cout;
    using std::endl;
    using std::min;
    using std::max;
    using std::vector;
    using std::string;
    using std::fill;
    int n;
    cin >> n;
    string s;
    cin >> s;


    fill(ba,ba+4003,false);
    for(int i=0; i<n; i++){
        ba[i]=(s[i]=='B');
    }

    vector<int> r,g,b;
    for(int i=0; i<n; i++){
        if(s[i]=='R') r.push_back(i);
        if(s[i]=='G') g.push_back(i);
        if(s[i]=='B') b.push_back(i);
    }

    int rs = r.size();
    int gs = g.size();
    int bs = b.size();

    ll sum = rs * (long long)gs * bs;
    for(int i=0; i<rs; i++){
        for(int j=0; j<gs; j++){
            int ri = r.at(i);
            int gj = g.at(j);
            int mx = max(ri,gj);
            int mn = min(ri,gj);
            int df = mx-mn;
            if(mx+df<n && ba[mx+df])sum--;
            if(df%2==0 && ba[(ri+gj)/2])sum--;
            if(mn-df>=0 && ba[mn-df])sum--;
        }
    }

    cout << sum << endl;
    return 0;
}

