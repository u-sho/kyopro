#include<iostream>
int main(){
    using std::cin;
    using std::cout;
    using std::endl;
    using std::string;

    int n;
    cin >> n;

    --n;
    n %= 30;
    ++n;

    string ans ="123456";
    for(int i=0; i<n; ++i) {
        std::swap(ans[i%5], ans[i%5+1]);
    }

    cout << ans << endl;
    return 0;
}