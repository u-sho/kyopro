#include <bits/stdc++.h>
using namespace std;
int main() {
	string S;
	uint N;
	cin >> S;
	cin >> N;
	for (uint i=N; i<S.length()-N; i++){
		cout << S[i];
	}
	cout << endl;
}
