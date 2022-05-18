#include <bits/stdc++.h>

using namespace std;
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int A, B;
    cin >> A >> B;
    
    vector<int> E(A+B);
    for(int i=0; i<A; i++) E[i] = i+1;
    for(int j=0; j<B; j++) E[A+j] = -j-1;
    if (A<B) E[A-1] += B*(B+1)/2 - A*(A+1)/2;
    else E[A+B-1] -= A*(A+1)/2 - B*(B+1)/2;

    for(int i=0; i<A+B-1; i++) cout << E[i] << ' ';
    cout << E[A+B-1] << "\n";

    return 0;
}
