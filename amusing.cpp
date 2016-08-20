#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define ull unsigned long long int

int main()
{
  int t;
  cin>>t;
  for(int i=0;i<t;i++)
  {
    ull n;
    cin>>n;
    n++;
    string s="";
    while(n!=0)
    {
      if(n&0x1==1)s="1"+s;
      else s="0"+s;
      n=n>>1;
    }
    for(int j=1;j<s.length();j++)
    if(s[j]=='0')cout<<5;
    else cout<<6;
    cout<<endl;
  }
}
