#include<iostream>
#include<vector>
#include<math.h>

using namespace std;
vector<int> v,prim;

bool primes(int n)
{
  //prim[0]=1;prim[1]=1;
  for(int i=2;i*i<=n;i++)if(n%i==0)return false;

  return true;
}


bool choose(int n)
{
  int sum=0;
  for(int i=1;i*i<=n;i++)
  {
    if(n%i==0&&i*i!=n){sum+=i;sum+=n/i;}
    else if(i*i==n) sum+=i;
  }
  //cout<<n<<" "<<sum<<endl;
  if(primes(sum))return true;
  return false;
}

int main()
{

  v.resize(1000007);
  //prim.resize(1000006);
  //primt();
  for(int i=2;i<=1000;i++)
  {
    if(choose(i*i))
    v[i*i]=1;
  }
  v[2]=1;
  for(int i=0;i<1000007;i++)
  {
    v[i]=v[i-1]+v[i];
  }
  int t,a,b;
  cin>>t;
  for(int i=0;i<t;i++)
  {
    cin>>a>>b;
    cout<<v[b]-v[a-1]<<endl;
  }

}
