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
	string s1,s2;
	cin>>s1>>s2;
	vi front(s2.length()),back(s2.length());
	//construct front here
	int x=0,y=0;
	while(x<s1.size()&&y<s2.size())
	{
		if(s1[x]==s2[y])
		{
			front[y]=x;
			x++;
			y++;
		}
		else x++;
	}
	while(y<s2.size())
	{
		front[y]=1000000;
		y++;
	}

	//construct back here
	x=s1.size()-1;y=s2.size()-1;
	while(x>=0&&y>=0)
	{
		if(s1[x]==s2[y])
		{
			back[y]=x;
			x--;
			y--;
		}
		else x--;
	}
	while(y>=0)
	{
		back[y]=-1;
		y--;
	}
	front.insert(front.begin(),-1);
	//do the remaining calculation here
	//foi(front.size())cout<<front[i]<<" ";cout<<endl;
	//foi(back.size())cout<<back[i]<<" ";cout<<endl;
	int begin,end,len=1000000;
	foi(front.size())
	{
		if(front[i]==1000000)break;
		vector<int>::iterator it;
		it=upper_bound(back.begin(),back.end(),front[i]);
			if(it-back.begin()-i<len)
			{
				begin=i-1;
				end=max(begin+1,int(it-back.begin()));
				len=it-back.begin()-i;
			}
	}
	//cout<<begin<<" "<<end<<endl;
	//cout<<len<<endl;
	if(len<int(s2.size())&&!(begin<0&&end>=s2.size()))
	{
		foi(begin+1)
		{
			cout<<s2[i];
		}
		for(int i=end;i<s2.size();i++)
		{
			cout<<s2[i];
		}
		cout<<endl;
	}
	else
	{
		cout<<"-"<<endl;
	}


}