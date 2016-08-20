#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


int main()
{
  int i=0;
  vector<int> v;
  v.resize(4);
  while(cin>>v[0])
  {i++;
    cin>>v[1]>>v[2]>>v[3];
    sort(v.begin(),v.end());
    cout<<"Case "<<i<<": "<<v[3]+v[2]<<endl;
  }
}
