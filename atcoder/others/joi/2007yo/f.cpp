#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> joi_city(20, vector<int>(20, 0));

int main() {
	unsigned a, b;
	cin >> a >> b;

	unsigned n;
	cin >> n;
	for (unsigned i = 0u; i < n; i++) {
		unsigned x, y;
		cin >> x >> y;
		joi_city.at(x).at(y) = -1;
	}

	for (unsigned i = 1u; i <= a; i++) {
		if (joi_city[i][1] == -1) break;
		joi_city[i][1] = 1;
	}

	for (unsigned j = 2; j <= b; j++) {
		for (unsigned i = 1; i <= a; i++) {
			if (joi_city[i][j] == -1) continue;
			joi_city[i][j] = max(joi_city[i-1][j],0) + max(joi_city[i][j-1],0);
		}
	}

	cout << joi_city[a][b] << '\n';
	return 0;
}

