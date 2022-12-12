#include <iostream>
int main(){
  unsigned N;
  std::cin >> N;
  std::cout << int(N/10u == N%10u) << '\n';
  return 0;
}
