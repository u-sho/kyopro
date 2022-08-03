#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    int n;
    cin >> n;
    int a[n-1][n-1];
    bool d[n+1][n+1];
    for(int i=0; i<n; i++)for(int j=0; j<n; j++)cin >> a[i][j];
    fill(d[0], d[n+1], false);

    for(int j=0; j<n; j++) {
        for(int i=0; i<n; i++) {
            if(d[a[i][j]][i+1])
        }
    }
    return 0;
}