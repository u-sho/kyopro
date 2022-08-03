#include<bits/stdc++.h>
long long go_jo[1000];
int main(){
    for(long long i=0LL; i<1000LL; i++){
        go_jo[i] = pow(i,5);
    }
    int x;
    std::cin >> x;
    int a=10000, b=10000;
    for(int i=0; i<1000; i++){
        if(a!=10000) break;
        for(int j=i+1; j<1000; j++){
            if(go_jo[i]+go_jo[j] == x) {
                a=i;
                b=-j;
                break;
            }
            if(go_jo[i]-go_jo[j] == x) {
                a = i;
                b = j;
                break;
            }
            if(-go_jo[i]+go_jo[j] == x) {
                a=j;
                b=i;
                break;
            }
            if(-go_jo[i]-go_jo[j] == x) {
                a = -i;
                b = j;
                break;
            }
        }
    };

    std::cout << a << ' ' << b << std::endl;
    return 0;
}