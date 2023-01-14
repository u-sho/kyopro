#include <bits/stdc++.h>
using namespace std;

[[nodiscard]] unsigned f(unsigned x) {
  unsigned ret = x % 10U;
  while (x /= 10U) ret += x % 10U;  // 高々9回
  return ret;
}

int main() {}