#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s;
	int cas=1;
	while(cin>>s)
	{
		s="0"+s;
		int ans=0;
		for(int i=1;i<s.length();i++)
		{
			if(s[i]!=s[i-1])ans++;
		}
		cout<<"Game #"<<cas<<": "<<ans<<endl;
		cas++;
	}
}