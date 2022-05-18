#include<iostream>
#include<string>
int main(){
    std::string s;
    std::cin >> s;
    if(s[1]=='B') std::cout<<"ARC\n";
    else std::cout << "ABC\n";
    return 0;
}