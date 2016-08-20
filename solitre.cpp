#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int sd(char a, char b)
{
	if(a==b)return 1;
	return 2;
}

int main()
{
	string s1,s2;
	cin>>s1>>s2;
	while(s1!="*"&&s2!="*")
	{
		int cnt;
		if(s1[0]==s2[0])cnt=0;
		else cnt=1;
		for(int i=1;i<s1.length();i++)
		{
			if(sd(s1[i-1],s2[i-1])==sd(s1[i],s2[i])){}
			else cnt++;
		}
		if(s1[s1.length()-1]==s2[s2.length()-1])cnt--;
		if(cnt<0)cout<<0<<endl;
		else
		{
			if(cnt%2==0)cout<<cnt/2<<endl;
			else cout<<(cnt+1)/2<<endl;
		}
		cin>>s1>>s2;

	}
}