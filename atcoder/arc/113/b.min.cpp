#include <atcoder/all>
main() {
  int A, B, C;
  std::cin >> A >> B >> C;
  std::cout << atcoder::pow_mod(A, atcoder::pow_mod(B, C, 84), 10);
}