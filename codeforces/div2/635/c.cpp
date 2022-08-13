#include <bits/stdc++.h>
using namespace std;

// 首都を根に各都市の深さを測る(𝑶(n))
// 一番深いところから順に工業都市にする
// （同時に葉の工業都市の数を数える(足し算)
// 観光都市の葉の工業都市の数を数える（足し算）𝑶(n-k)
// 根までついたら終わり

vector<int> q[200005];
int dpth[200005] = { 0, 1,};
int n,k;
int cnt = 1;
int solve(int p=1, int d = 2) { // p arent, d epth
    for(int i=0; i<q[p].size(); i++){
        if (dpth[q[p][i]]!=0) continue;
        dpth[q[p][i]] = d;
        cnt++;
    }
    if (cnt == n) return;
    for(int i=0; i<q[p].size(); i++){

    }
}

int main(){
    cin >> n >> k;

    for(int i=1; i<n; i++){
        int a,b;
        cin >> a >> b;
        // if (a<b) swap(a,b);
        q[a].push_back(b);
        q[b].push_back(a);
    }



    return 0;
}