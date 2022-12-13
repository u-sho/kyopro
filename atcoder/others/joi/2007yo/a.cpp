#include <iostream>
#include <algorithm>
int main(){
  int infomatics, mathematics, science, english, S;
  std::cin >> infomatics >> mathematics >> science >> english;
  S = infomatics + mathematics + science + english;
  std::cin >> infomatics >> mathematics >> science >> english;
  std::cout << std::max(S, infomatics+mathematics+science+english) << '\n';
  return 0;
}
