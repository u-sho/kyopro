#include<bits/stdc++.h>
using namespace std;
int main(){
	int N;
	cin>>N;
	pair<string,string>S[N];
	for(auto&[s,i]:S)cin>>s>>i;
	sort(S,S+N);
	for(auto [s,i]:S)cout<<s+" "+i+"\n";
}
