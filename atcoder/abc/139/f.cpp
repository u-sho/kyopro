#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

long double len(double x, double y) {
    return x*x + y*y;
}

int main(void){
    int n;
    cin >>n;
    ll x[n], y[n];
    for(int i=0; i<n; i++)cin>>x[i]>>y[i];

    double nowLen = 0.0, nowX=0.0, nowY=0.0, ans = 0.0;
    bool used[n];
    fill(used, used+n, false);
    for(int i=0; i<n; i++) { //now using
        nowLen = len(x[i],y[i]);
        nowX = x[i]; 
        nowY = y[i];
        used[i] = true;
        for(int j=0; j<n; j++) {
            if(i!=j) {
                if (nowLen < len(nowX+x[j], nowY+y[j]) ) {
                    used[j] = true;
                    
                }
            }
        }
    }

    return 0;
}