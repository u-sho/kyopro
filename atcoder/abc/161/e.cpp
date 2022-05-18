#include <bits/stdc++.h>
using ll = long long;

const std::string ans[2] = { "No\n", "Yes\n" };
constexpr ll MOD = 1'000'000'007;
// constexpr ll MOD = 998'244'353;
int main() {
    using namespace std;
    int n,k,c;
    cin >> n >> k >> c;
    string s;
    cin >> s;

    int lastWorkDay=1;
    int firstWorkDay=n;

    int kk=0;
    for(int i=0; i<n; i++){
        if(s[i]=='o'){
            lastWorkDay = i+1;
            i+=c-1;
            kk++;
            if(kk==k){
                break;
            }
        }
    }
    kk=0;
    for(int i=n-1; i>=0; i--){
        if(s[i]=='o'){
            firstWorkDay=i+1;
            i-=c-1;
            kk++;
            if(kk==k)break;
        }
    }
    
    cout << ((firstWorkDay == lastWorkDay) ? firstWorkDay : '\0') << endl;
    return 0;
}