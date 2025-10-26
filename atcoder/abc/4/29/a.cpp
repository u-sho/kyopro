#include<iostream>
int main(){
  uint N,M;
  std::cin >> N >> M;
  for(uint i=1; i<=N; i++){
    std::cout << (i<=M ? "OK\n" : "Too Many Requests\n");
  }
}