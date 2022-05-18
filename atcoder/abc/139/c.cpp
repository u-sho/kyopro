#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    int n;
    cin >> n;
    int h[n];
    for(int i=0; i<n; i++)cin >> h[i];

    int cnt=0, ans=0;
    for(int i=1; i<n; i++) {
        if(h[i-1]<h[i]) {
            ans = max(cnt, ans);
            cnt = 0;
        } else {
            cnt++;
            ans = max(cnt, ans);
        }
    }

    cout << ans << endl;

    return 0;
}
