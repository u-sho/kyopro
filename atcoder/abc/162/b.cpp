#include<iostream>
using ll = long long;

int main() {
    using namespace std;
    int n;
    cin >> n;
    ll sum = 0LL;
    for(int i=1; i<=n; i++){
        if(i%3!=0 && i%5!=0) sum+=i;
    }
    cout << sum <<endl;
    return 0;
}

