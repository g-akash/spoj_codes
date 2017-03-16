#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		string s;
		cin>>s;
		string ans="YES";
		int len=s.length()/2+1;
		for(int j=0;j<len&&j<s.length();j++)
		{
			if(s[j]==s[s.length()-1-j]&&(s[j]=='0'||s[j]=='1'||s[j]=='8'))continue;
			ans="NO";
		}
		cout<<ans<<endl;
	}
}
