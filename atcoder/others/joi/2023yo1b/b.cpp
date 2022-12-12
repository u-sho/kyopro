#include<iostream>

int main(){
  using namespace std;
  unsigned A, B;
  cin >> A >> B;
  if (A < B) cout << "-1\n";
  if (A == B) cout << "0\n";
  if (A > B) cout << "1\n";
}
