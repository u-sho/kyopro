#include<iostream>
using namespace std;
int main(){
    string ans;
    char s[4];
    int sint;
    cin >> sint;
    s[0] = sint/1000;
    s[1] = (sint%1000)/100;
    s[2] = (sint%100)/10;
    s[3] = (sint%10);
    if(s[0]==s[1] || s[1]==s[2] || s[2]==s[3]){
        ans = "Bad";
    }else{
        ans = "Good";
    }
    cout << ans << endl;
    return 0;
}