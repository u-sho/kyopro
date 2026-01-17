#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	uint N, M;  // <=26
	string S, T;
	uint Q;  // <=100
	cin >> N >> M;
	cin >> S;
	cin >> T;
	cin >> Q;
	vector<string> w(Q);  // <=100
	for (string& wi : w) cin >> wi;
	// ranges::sort(wi);
	// wi.erase(std::unique(begin(wi), end(wi)), end(wi));

	for (const auto& wi : w) {
		bool is_Takahashi = true;
		bool is_Aoki      = true;
		for (const auto wij : wi) {
			bool is_Takahashi_char = false;
			bool is_Aoki_char      = false;
			for (const auto Si : S)
				if (Si == wij) is_Takahashi_char = true;
			for (const auto Ti : T)
				if (Ti == wij) is_Aoki_char = true;
			if (!is_Takahashi_char) is_Takahashi = false;
			if (!is_Aoki_char) is_Aoki = false;
		}
		if (is_Takahashi && is_Aoki) cout << "Unknown\n";
		else if (is_Aoki) cout << "Aoki\n";
		else if (is_Takahashi) cout << "Takahashi\n";
	}

	return 0;
}
