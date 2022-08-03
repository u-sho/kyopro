#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
struct v {
  int from[2];
  int to[2];
};

int h, w;
int m[80][80]; // a-b
vector<v> d;

int solve(){
  
}

int main(){
  cin >> h >> w;
  for(int i=0; i<h; i++){
    for(int j=0; j<w; j++){
      cin >> m[i][j];
    }
  }
  for(int i=0; i<h; i++){
    for(int j=0; j<w; j++){
      int b;
      cin >> b;
      m[i][j] -= b;
    }
  }
  for(int j=0; j<h; j++){
    for(int i=1; i<w; i++){
      v tmp;
      tmp.from=[j,i-1];
      tmp.to=[j,i];
      d.push_back(tmp);
    }
  }
  for(int i=1; i<h; i++){
    for(int j=0; j<w; j++){
      v tmp;
      tmp.from=[i-1,j];
      tmp.to=[i,j];
      d.push_back(tmp);
    }
  }
  cout << solve() << endl;
  return 0;
}