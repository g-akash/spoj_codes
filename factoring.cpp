#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
#define ull unsigned long long int

vector<ull> v;
void champu()
{
  for(ull i=1;i<1000001;i++)
  {
    for(ull j=2*i;j<1000003;j+=i)
    {
      v[j]+=i;
    }
  }
  return;
}



int main()
{

  v.resize(1000006);
  for(int i=0;i<1000006;i++)v[i]=0;
  champu();
  for(int i=1;i<=1000000;i++)v[i]+=v[i-1];
  int t,x;
//for (int i = 0; i < 10; i++) {cout<<v[i]<<endl;
  /* code */
//}
  cin>>t;

  for(int i=0;i<t;i++)
  {
    cin>>x;
    cout<<v[x]<<endl;
  }

}
