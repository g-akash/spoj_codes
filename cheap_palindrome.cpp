#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int a,b;
		string s,palin="YES";
		int ans=0;
		cin>>s;
		cin>>a>>b;
		int len=s.length();
		for(int j=0;j<len/2;j++)
		{
			if(s[j]==s[len-1-j]&&s[j]!='/')continue;
			if(s[j]!=s[len-1-j]&&s[j]!='/'&&s[len-1-j]!='/'){palin="NO";continue;}
			if(s[j]==s[len-1-j]&&s[j]=='/'){ans+=2*min(a,b);continue;}
			if(s[j]!=s[len-1-j]&&s[j]=='/'){if(s[len-1-j]=='a')ans+=a;else ans+=b;continue;}
			if(s[j]!=s[len-1-j]&&s[len-1-j]=='/'){if(s[j]=='a')ans+=a;else ans+=b;continue;}
		}
		if(palin=="YES")cout<<ans<<endl;
		else cout<<-1<<endl;
	}
}	
