#include <bits/stdc++.h>
int main(){
    int a,b;
    std::cin>>a>>b;
    a=a==1?14:a;
    b=b==1?14:b;
    std::string str[3] = {"Alice", "Draw", "Bob"};
    std::string* ans = &str[1];
    std::cout<<ans[(a>b?-1:(a==b?0:1))] << std::endl;
    return 0;
}