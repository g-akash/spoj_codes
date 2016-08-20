#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

string revi(string s)
{
  string ans="";
  for(int i=0;i<s.length();i++)
  {
    ans=s.substr(i,1)+ans;
  }
  return ans;
}

int main()
{
  int col;
  string s,ans;
  cin>>col;
  while(col!=0)
  {
    ans="";
    cin>>s;
    vector<string> v;
    for(int i=0;i<s.length();i+=col)
    {
      v.push_back(s.substr(i,col));
    }
    for(int i=1;i<v.size();i+=2)
    {
      v[i]=revi(v[i]);
    }
    for(int i=0;i<v[0].length();i++)
    {
      for(int j=0;j<v.size();j++)
      {
        ans+=v[j].substr(i,1);
      }
    }
    cout<<ans<<endl;
    cin>>col;
  }
}
