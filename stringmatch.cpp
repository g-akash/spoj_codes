#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	int t;
	cin>>t;
	string a,b;
	for(int i=0;i<t;i++)
	{
		cin>>a>>b;
		string ans="Yes";
		for(int j=0;j<a.length();j++)
		{
			if(a[j]!='?'&&b[j]!='?'&&a[j]!=b[j])ans="No";
		}
		cout<<ans<<endl;
	}
}
