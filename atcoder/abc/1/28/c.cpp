#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
using namespace std;

int main() {
	int n, m, ans=0;
    int k[10], p[10], s[10][10];

    cin >> n >> m;
    for(int i=0; i<m; i++){
      cin >> k[i];
      for(int j=0; j<k[i]; j++){
        cin >> s[i][j];
      }
    }
    for(int i=0; i<m; i++){
        cin >> p[i];
    }

    for(int ii=0; ii<(1<<n); ii++){
        bitset<11> isOnBits(ii);
        string isOn = isOnBits.to_string().substr(11-n);
        for(int i=0; i<m; i++){
            int sum =0;
            for(int j=0; j<k[i]; j++){
                sum += isOn[ s[i][j] -1 ] == '1' ? 1 : 0;
            }
            if(sum%2 != p[i]) break;
            if(i==m-1) ans++;
        }
    }

    cout << ans << endl;

    return 0;
}