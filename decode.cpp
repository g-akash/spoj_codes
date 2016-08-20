#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
  vector<int> v;
  v.resize(26);

  v[0]=16;v[1]=17;v[2]=18;v[3]=19;v[4]=20;
  v[5]=21;v[6]=22;v[7]=23;v[8]=24;v[9]=25;
  v[10]=26;v[11]=27;v[12]=28;/*here*/v[13]=20;v[14]=21;
  v[15]=22;v[16]=23;v[17]=24;v[18]=25;v[19]=26;
  v[20]=18;v[21]=19;v[22]=20;v[23]=21;v[24]=22;
  v[25]=23;
  string s;
  while(cin>>s&&s.length()>3)
  {
    int count=0;
    for(int i=0;i<s.length();i++){cout<<v[int(s[i])-97]<<" ";if(v[int(s[i])-97]>23)count++;}cout<<endl;
    if(count>0)cout<<count<<endl;
    else cout<<"no one."<<endl;

  }
}
