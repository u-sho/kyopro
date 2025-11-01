#include <bits/stdc++.h>
using namespace std;
int main() {
	uint A, B, C, D;
	cin >> A >> B >> C >> D;
	if (A <= C && B > D) {
		cout << "Yes\n";
	} else cout << "No\n";
	return 0;
}
