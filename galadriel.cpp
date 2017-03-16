#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;


string reverse(string s)
{
	string ans="";
	for(int i=0;i<s.length();i++)
		ans=s.substr(i,1)+ans;
	return ans;
}

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		string s,var,vex;
		unordered_map<string,int> m;
		cin>>s;
		for(int j=0;j<s.length();j++)
		{
			for(int k=j+1;k<=s.length();k++)
			{
				m[s.substr(j,k-j)]=1;
			}
		}
		bool ans=true;
		for(int j=0;j<s.length();j++)
		{
			for(int k=j+1;k<=s.length();k++)
			{
				vex=s.substr(j,k-j);
				if(m.find(reverse(vex))==m.end())ans=false;
			}
		}
		if(ans)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;

	}
}