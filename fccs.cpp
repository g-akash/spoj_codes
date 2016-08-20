#include<iostream>
#include<algorithm>

using namespace std;

#define ull unsigned long long int

int main()
{
  int t;
  cin>>t;
  ull n,ans;
  for(int i=0;i<t;i++)
  {
    cin>>n;
    ans=0;
    for(ull j=1;j*j<=n;j++)
    {
      if(n%j==0&&j*j!=n){ans+=j;ans+=n/j;}
      else if(j*j==n)ans+=j;
    }
    cout<<ans<<endl;
  }

}
