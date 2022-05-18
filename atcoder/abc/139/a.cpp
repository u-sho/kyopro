#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void){

    string s,t;
    cin >> s;
    cin >> t;
    int ans=0;
    for(int i=0; i<3; i++){
        if(s[i]==t[i]) ans++;
    }
    cout << ans << endl;
    return 0;
}

#import<iostream>
main(){std::string a,b;std::cin>>a>>b;std::cout<<(a[0]==b[0])+(a[1]==b[1])+(a[2]==b[2]);}


#import<cstdio>
main(){char a[3],b[3];scanf("%s%s",a,b);printf("%d",(a[0]==b[0])+(a[1]==b[1])+(a[2]==b[2]));}

