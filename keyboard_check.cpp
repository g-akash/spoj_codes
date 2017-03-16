#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>
#include <map>
#include <queue>
#include <algorithm>
#include <list>

using namespace std;


#define ll long long int
#define umm(x,y) unordered_map<x,y >
#define pb push_back
#define foi(n) for(int i=0;i<n;i++)
#define foj(n) for(int j=0;j<n;j++)
#define foi1(n) for(int i=1;i<=n;i++)
#define vi vector<int>
#define vvi vector<vi >
#define vll vector<ll>
#define vvll vector<vll >
#define si size()


int main()
{

	string s1, s2;

	char ch[26];
	foi(26)ch[i]='M';

	cin>>s1>>s2;
	foi(s1.length())
	{
		if(s1[i]==s2[i])
		{
			if(ch[int(s1[i])-97]!='M'&&ch[int(s1[i])-97]!='N')
			{
				cout<<-1<<endl;
				return 0;
			}
			ch[int(s1[i])-97]='N';
		}
		else
		{
			if(ch[int(s1[i])-97]=='N'||ch[int(s2[i])-97]=='N')
			{
				cout<<-1<<endl;
				return 0;
			}
				if((ch[int(s1[i])-97]!=s2[i]&&ch[int(s1[i])-97]!='M')||(ch[int(s2[i])-97]!=s1[i]&&ch[int(s2[i])-97]!='M'))
				{
					cout<<-1<<endl;
					return 0;
				}
				ch[int(s1[i])-97]=s2[i];
				ch[int(s2[i])-97]=s1[i];
		}
	}
	int count=0;
	foi(26)if(ch[i]!='M'&&ch[i]!='N')count++;
	cout<<count/2<<endl;
	foi(26)
	{
		if(int(ch[i])-97>i)cout<<char(i+97)<<" "<<ch[i]<<endl;
	}
}