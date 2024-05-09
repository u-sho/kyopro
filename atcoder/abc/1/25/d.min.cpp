#include<bits/stdc++.h>
using namespace std;long o,s,m=1e9,A;main(){for(cin>>A;cin>>A;s+=A=abs(A),m=min(m,A))o^=A<0;cout<<s-(o?m*2:0);}