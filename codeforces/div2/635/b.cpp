#include <iostream>
int main(){
    int t;
    std::cin >> t;
    while(t--){
        int x,n,m;
        std::cin>>x>>n>>m;

        while(n--){
            if (x>20) {
                x/=2;
                x+=10;
            }
            else break;
        }
        while(m--){
            x-=10;
        }

        std::cout << (x<=0 ? "YES\n" : "NO\n");
    }
    return 0;
}