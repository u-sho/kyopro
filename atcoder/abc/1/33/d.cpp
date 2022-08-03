#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int* solve(int n, int *a[], int *m[]){
    for(int i=0; i<n; i++){
        if(m[i]+m[i+1]>a[i]){
            if(m[i+])
        }
    }
}

int main(void){

    int n; //odd number, n<1e5
    cin>>n;

    int m[m];
    int a[n]; // a<=1e9
    int a_min=1000000009;//1e9+
    for(int i=0; i<n; i++){
        cin>>a[i];
        a_min=min(a_min,a[i]);
    }
    m[0] = min(a[0],a[n-1]);
    for(int i=1; i<n; i++){
        m[i] = min(a[i-1],a[i]);
    }





    return 0;
}