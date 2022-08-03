#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
// const double MIN_ERR = 0.0000001;
int sqs[4003];
void emuSqs(){
    for(int i=0; i<=4000; i++){
        sqs[i] = i*i;
    }
    return;
}

int main(void){
    int d,n;
    cin>>n>>d;
    int x[n][d];
    for(int i=0; i<n; i++){
        for(int j=0; j<d; j++){
            cin>>x[i][j];
        }
    }

    int ans=0;
    emuSqs();
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int sqsum=0.0;
            for(int k=0; k<d; k++){
                sqsum += (x[i][k]-x[j][k])*(x[i][k]-x[j][k]);
            }
            for(int i=0; i<=4000; i++){
                if(sqs[i]==sqsum){
                    ans++;
                    break;
                }
            }
            // double dist=sqrt(sqsum);
            // if(abs(ceil(dist)-dist)<MIN_ERR){
            //     ans++;
            // }
        }
    }
    cout << ans << endl;
    return 0;
}