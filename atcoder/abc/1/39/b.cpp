#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    int a, b;
    cin >> a >> b;
    int ans = (b-1)%(a-1) ? ((b-1)/(a-1) + 1) : ((b-1)/(a-1));
    cout << ans << endl;
    return 0;
}

#import<iostream>
main(){int a,b;std::cin>>a>>b;std::cout<<(a+b-3)/--a;}

a,b;main(){scanf("%d%d",&a,&b);printf("%d",(a+b-3)/--a);}