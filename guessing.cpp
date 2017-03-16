#include<iostream>
#include<vector>
#include<math.h>
#include<string>

using namespace std;

long long int hcf(long long int x, long long int y)
{
	if(x%y==0)return y;
	else return hcf(y,x%y);
}

long long int lcm(long long int x, long long int y)
{
	long long int z=hcf(x,y);
	return (x*y)/z;
}

int main()
{
	string s;
	cin>>s;
	while(s!="*")
	{
		bool y=true;
		long long int ans=1;
		for(long long int i=0;i<s.length();i++)
		{
			if(s[i]=='Y')ans=lcm(ans,i+1);
		}
		for(long long int i=0;i<s.length();i++)
		{
			if(s[i]=='N'&&ans%(i+1)==0)y=false;
		}
		if(y)cout<<ans<<endl;
		else cout<<-1<<endl;
		cin>>s;
	}

}