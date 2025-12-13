#include <bits/stdc++.h>
using namespace std;
int main() {
	uint N;
	string S;
	cin >> N;
	cin >> S;
	for (uint i = 0; i + S.length() < N; i++) cout << 'o';
	cout << S << '\n';
}
