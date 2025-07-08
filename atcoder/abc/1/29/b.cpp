#include<bits/stdc++.h>
using namespace std;
int main(){
	uint N;
	cin >> N;
	vector<uint> W(N);
	for (uint& Wi : W) cin >> Wi;

	uint sum = 0, S1 = 0, sub = 400000;
	for (const uint Wi : W) sum += Wi;
	for (uint T = 1; T < N; T++) {
		S1 += W[T - 1];
		uint S2 = sum - S1;
		if (S1 > S2) {
			if (sub > S1 - S2) sub = S1 - S2;
		} else if (sub > S2 - S1) sub = S2 - S1;
	}
	cout << sub << endl;

	return 0;
}
