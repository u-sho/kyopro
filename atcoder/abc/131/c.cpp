#include<iostream>
// #include<numeric>
using namespace std;

long long gcd(long long a, long long b) {//a<b
    long long r = b%a;
    while(r) {
        b=a;
        a=r;
        r=b%a;
    }
    return a;
}

long long lcm(long long a, long long b) {//a<b
    if(a==b) return a;
    if(a==1 || a==2 || a==3) return a*b;
    return ((unsigned long long)a*(unsigned long long)b)/(unsigned long long)gcd(a,b);
}

int main() {
  long long A, B, C, D;
  cin >> A >> B >> C >> D;
  if(C>D) {
    swap(C,D);
  }//C<D

  if(B<C) {
    cout << B-A+1 << endl;
    return 0;
  }
  
  long long LCMofCandD = lcm(C,D);
  long long divisiblesA = (A-1)/C + (A-1)/D - (A-1)/LCMofCandD;
  long long divisiblesB = B/C + B/D - B/LCMofCandD;

  cout << (B - divisiblesB) - (A - divisiblesA) + 1 << endl;

  return 0;
}
