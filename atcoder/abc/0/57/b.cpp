#include<bits/stdc++.h>
using namespace std;
int main(){
	uint N,M;
	cin >> N >> M;
	vector<pair<int,int>> students(N), check_points(M);
	for(auto& ab : students) cin >> ab.first >> ab.second;
	for(auto& cd : check_points) cin >> cd.first >> cd.second;

	for(const auto &[a,b] : students){
		uint distance = 400'000'008U;
		uint check_point = 0;
		for(uint i=0; i<M; i++){
			const auto &[c,d] = check_points[i];
			if (abs(a-c) + abs(b-d) < distance){
				distance = abs(a-c) + abs(b-d);
				check_point = i+1;
			}
		}
		cout << check_point << "\n";
	}
	return 0;
}
