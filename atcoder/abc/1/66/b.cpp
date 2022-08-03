#include<iostream>
#include<algorithm>
int main(){
    using namespace std;
    int n, k;
    std::cin >> n >> k;
    bool moratta[n];
    fill(moratta, moratta+n, false);
    for(int i=0; i<k; i++){
        int d;
        cin >> d;
        for(int j=0; j<d; j++){
            int a;
            cin >> a;
            moratta[a-1] = true;
        }
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        if(!moratta[i])ans++;
    }
    cout << ans << endl;
    return 0;
}