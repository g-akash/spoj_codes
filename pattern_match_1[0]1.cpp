#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	string s;
	cin>>s;
	int start=-1,ans=0,str_length=s.length();
	for(int i=0;i<str_length;i++)
	{
		if(s[i]=='0')
		{
			continue;
		}
		else if(s[i]=='1')
		{
			if(start>=0)
				ans++;
			
			start=i;
		}
		else
		start=-1;
	}
	cout<<ans<<endl;
}
