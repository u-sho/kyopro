#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    int a,b,n;
    cin>>n>>a>>b;
    cout<<min(a*n,b)<<endl;
    return 0;
}