#include <cmath>
#include <string>
#include <vector>
#include <numeric> /* gcd, lcm, partial_sum, reduce*/
#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

int main(){
    // 2 <= N <= 1e5
    // 1 <= A_i <= 1e9
    int N;
    cin >> N;
    int A[N];
    for(int i=0; i<N; i++) cin >> A[i];

    int gcd_A = gcd(A[0], A[1]);
    for(int i=2; i<N; i++) gcd_A = gcd(gcd_A, A[i]); // O(N log_10(A[i])*5)最悪

    int A_div_gcd[N];
    for(int i=0; i<N; i++) A_div_gcd[i] = A[i] / gcd_A;

    for(int i=0; i<N; i++)
    return 0;
}