#include <bits/stdc++.h>
using namespace std;
int main() {
	uint H,W;
	cin >>H>>W;
	for(uint i=0; i<H; i++)for(uint j=0; j<W; j++){
		uint 隣接数 =0;
		if (i) 隣接数++;
		if (j) 隣接数++;
		if (i+1u<H) 隣接数++;
		if (j+1u<W) 隣接数++;
		cout << 隣接数 << ((j+1u<W)?' ': '\n');
	}
	return 0;
}
