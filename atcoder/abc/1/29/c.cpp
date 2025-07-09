#include<bits/stdc++.h>
using namespace std;
int main(){
	uint N, M;
	cin >> N >> M;
	vector<uint> a(M);
	for (uint& ai : a) cin >> ai;

	vector<uint> steps(N+1, 1);
	for (uint j = 0; j < M; j++) steps[a[j]] = 0;
	for (uint i = 2; i <= N; i++) {
		if (steps[i] == 0) continue;
		steps[i] = (steps[i - 1] + steps[i - 2]) % 1000'000'007u;
	}

	cout << steps[N] << endl;
	return 0;
}
