#include <cmath>
#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct question {
    int l;
    int r;
    Q(int l, int r) : l(l), r(r){}
    int d(){return r-l+1;}
    // int size(){return l;}
} Q;

bool operator<(const Q& q1, const Q& q2) {
    // return q1.size() < q2.size();
    return q1.l < q2.l;
};

int sum(Q *q, int n) { // O(n)
    Q _q = q[0];
    int _sum=0;
    for(int i=1; ; i++) {
        if(i==n-1){
            _sum+=_q.d();
            break;
        }
        if(q[i].l<=_r+1){
            _q.r = q[i].r;
            _q.l = min(q[i].l, _q.l);
        } else {
            _sum += _q.d();
            _q = q[i+1];
        }
    }
    return _sum;
}

int main(){
    int N;
    cin >> N;
    vector<Q> q, c1, c2;
    for(int i=0; i<N; i++){
        cin >> q[i].l >> q[i].r;
        c1[i] = q[i];
    }
    sort(q.begin(), q.end());
    sort(c1.begin(),c1.end());

    

    return 0;
}