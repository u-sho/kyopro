#include <iostream>
#include <vector>

int main() {
  using namespace std;

  unsigned N;
  cin >> N;
  vector<unsigned> A(2u*N);
  for (unsigned i = 0u; i < 2u*N-1u; i++) cin >> A[i];

  vector<bool> one_student_class(N+1u, false);
  for (const unsigned Ai : A) one_student_class.at(Ai) = !one_student_class.at(Ai);

  for (unsigned i = 1u; i<= N; i++) {
    if (one_student_class.at(i)) {
      cout << i << '\n';
      return 0;
    }
  }
  return 1;
}
