#include<vector>
#include<iostream>
#include<string>
#include<math.h>

using namespace std;

int main()
{
  int t;
  cin>>t;
  for(int i=0;i<t;i++)
  {
    int l,b;
    cin>>l>>b;
    if(l<=b)
    {
      if(l%2==0)
      {
        cout<<'L'<<endl;
      }
      else
      cout<<'R'<<endl;
    }
    else{
      if(b%2==0)
      {
        cout<<'U'<<endl;
      }
      else cout<<'D'<<endl;
    }
  }
}
