#include<iostream>
#include<vector>
#include<string>

using namespace std;

string stri(int var)
{
if(var==0)return "0";
else if(var==1)return "1";
else if(var==2)return "2";
else if(var==3)return "3";
else if(var==4)return "4";
else if(var==5)return "5";
else if(var==6)return "6";
else if(var==7)return "7";
else if(var==8)return "8";
else if(var==9)return "9";
return "0";
}


string sdiv(string s)
{
string ans="";
int carry =0;
int i=0;
while(i<s.length())
{int var = carry*10+int(s[i])-48;carry = var%2;var/=2;ans+=stri(var);i++;}
return ans;
}


int main()
{
int t;
cin>>t;
for(int i=0;i<t;i++)
{
string s1,s2;
int k;
cin>>s1>>s2>>k;
if(s1.length()>18)s1=s1.substr(s1.length()-18);
int count=1;
bool doo=true;
for(int i=0;i<k&&doo;i++)
{
char ch=s1[s1.length()-1];
if(ch=='0'||ch=='2'||ch=='4'||ch=='6'||ch=='8')
{
s1=sdiv(s1);
count*=2;
}
else doo=false;
}
cout<<count<<endl;
}

}