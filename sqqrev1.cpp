#include <iostream>
#include <math.h>
using namespace std;
int main(){long long n,half_n,x,ans,srt;
while(cin>>n){x=0;
half_n=n/2;
ans=0;
while(x*x<=half_n){srt = int(sqrt(n-x*x));
if(srt*srt+x*x==n)ans+=1;
x+=1;}
cout<<ans<<endl;}}