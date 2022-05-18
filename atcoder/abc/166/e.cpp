#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::pair;
using std::sort;

bool ope(const pair<int,bool> &p1, const pair<int,bool> &p2){
    return p1.first < p2.first;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<pair<int,bool>> a_add_i(n), a_minus_i(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
        bool isChofuku = (a[i]+i+1 == a[i]-(i+1));
        a_add_i[i] = std::make_pair(a[i] + i + 1, isChofuku);
        a_minus_i[i] = std::make_pair(a[i] - (i + 1), isChofuku);
    }

    sort(a_add_i.begin(), a_add_i.end(), ope);
    sort(a_minus_i.begin(),a_minus_i.end(),ope);


    // a_add_i と a_minus_i の値が一致するものの中で，添字が重複してないやつ
    decltype(a_add_i)::iterator low_add_it = a_add_i.begin();
    decltype(a_minus_i)::iterator low_mns_it = std::lower_bound(a_minus_i.begin(),a_minus_i.end(),a_add_i.at(0));

    for(int i=0; i<n; i++){
        auto addi = std::upper_bound(a_add_i.begin(), a_add_i.end(), a_add_i.at(i)) - low_add_it;
        auto mnsi = std::upper_bound(a_minus_i.begin(), a_minus_i.end(), a_add_i.at(i)) - low_mns_it;
        
    }

    vector<int> 
    return 0;
}