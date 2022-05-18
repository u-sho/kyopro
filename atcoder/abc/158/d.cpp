#include <bits/stdc++.h>

int main() {
    using namespace std;
    string S; cin >> S;
    deque<char> ds;
    for(int i=0; i<S.length(); i++){
        ds.push_back(S[i]);
    }
    int q; cin >> q;
    bool isReversed = false;
    for(int i=0; i<q; i++){
        int t;
        cin >> t;
        if(t==1) {
            isReversed=!isReversed;
            continue;
        }
        int f;
        char c;
        cin >> f >> c;
        if((f==1 && !isReversed) || (f==2 && isReversed)){
            ds.push_front(c);
        } else{
            ds.push_back(c);
        }
    }
    for(int i=0; i<ds.size(); i++){
        if(isReversed)cout<<ds[ds.size()-1-i];
        else cout<<ds[i];
    }
    cout << endl;
    return 0;
}