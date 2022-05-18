#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct shop{
    int idx;
    string s;
    int p;

    shop(int inputed_index, string inputed_s, int inputed_p){
        idx = inputed_index;
        s = inputed_s;
        p = inputed_p;
    }

    bool operator<(const shop &cmp)const{
        return (s==cmp.s) ? (p>cmp.p) : (s<cmp.s);
    }
};

int main() {
	int n;
    vector<shop> shops;
    cin >> n;
    for(int i=0; i<n; i++){
        string str;
        int point;
        cin >> str >> point;
        shops.push_back(shop(i+1, str, point));
    }
    sort(shops.begin(),shops.end());
  
    for(int i=0; i<n; i++){
      cout << shops[i].idx << endl;
    }
  
    return 0;
}
