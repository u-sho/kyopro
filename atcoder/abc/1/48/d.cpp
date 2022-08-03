#include <iostream>

using namespace std;

int main(){
  int cnt=1, n,a;
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> a;
    if(a==cnt)cnt++;
  }
  cout << (cnt==1 ? -1 : n-cnt+1) << endl;
  return 0;
}