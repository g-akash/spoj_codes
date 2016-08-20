#include<iostream>
#include<vector>
#include<string>
#include<algorithm>


using namespace std;

#define ull long long int

ull fact(ull n)
{
	if(n==0)return 1;
	ull ans=1;
	for(ull i=1;i<=n;i++)ans*=i;
	return ans;
}

string str(string s, ull m)
{
	if(s.length()==1)return s;
	ull x=s.length()-1;
	ull y=fact(x);
	if(m%y==0)
	{
		ull z=m/y-1;
		string vx=s.substr(0,z)+s.substr(z+1);
		return s.substr(z,1)+str(vx,y);
		}
	else
	{
		ull z=m/y;
		string vx=s.substr(0,z)+s.substr(z+1);
		return s.substr(z,1)+str(vx,m%y);
		}
	}
	
ull nume(string s1, string s2)
{
	if(s1.length()==0)return 0;
	ull var=fact(s1.length()-1);
	ull i;
	for(i=0;i<s1.length();i++)
	{
		if(s1[i]==s2[0])
		{break;}
	}
	string s3=s1.substr(0,i)+s1.substr(i+1);
	return var*i+nume(s3,s2.substr(1));
}

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		string s,sx="aksh",st,ans="";
		ull m;
		cin>>s>>m;
		ull xy;
		st=s;
		s=s+"z";
		sort(&s[0],&s[s.length()]);
		s=s.substr(0,s.length()-1);
		xy=nume(st,s);
		cout<<str(s,m+xy+(ull)(1))<<endl;
	}
}
