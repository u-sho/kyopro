#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	uint P, Q, X, Y;
	cin >> P >> Q;
	cin >> X >> Y;
	if (P <= X && X < P + 100u && Q <= Y && Y < Q + 100) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}

	return 0;
}
