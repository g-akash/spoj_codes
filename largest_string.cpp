#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>
#include <map>
#include <queue>

using namespace std;


#define ll long long int
#define umm(x,y) unordered_map<x,y >
#define pb push_back
#define foi(n) for(int i=0;i<n;i++)
#define foj(n) for(int j=0;j<n;j++)
#define foi1(n) for(int i=1;i<=n;i++)
#define vi vector<int>
#define vvi vector<vi >
#define si size()


int main()
{
	int n,m;
	string s;
	cin>>n>>m>>s;
	int nex=0,al=0,mx=0;
	string ans="";
	int a[128]={0};
	int del[n];
	int mnn = min(m+1,n);
	map<int,int> mp;
	map<int,int>::iterator it;
	for(int i=0;i<mnn;i++)
	{
		mp[int(s[i])]++;
		if(int(s[i])>mx)mx=int(s[i]);
	}
	
	if(n==m)
	{
		cout<<endl;
		return 0;
	}
	nex=m+1;
	for(int i=0;i<n;i++)
	{
		//if something happens then del it
		if(int(s[i])!=mx)
		{
			del[i]=1;
			mp[int(s[i])]--;
			if(mp[int(s[i])]==0)mp.erase(mp.find(int(s[i])));
			continue;
		}
		//else don'e delete it
		del[i]=0;
		ans=ans+string(1,s[i]);
		mp[int(s[i])]--;
		if(mp[int(s[i])]==0)mp.erase(mp.find(int(s[i])));
		mp[s[nex]]++;
		nex++;
		it=mp.end();
		it--;
		mx=it->first;
		// if(int(s[nex-1])>mx)
		// {
		// 	mx=int(s[nex-1]);
		// }
		// else if(a[mx]==0) 
		// {
		// 	for(int i=mx;i>=0;i--)
		// 		if(a[i]!=0)
		// 		{
		// 			mx=i;
		// 			break;
		// 		}
		// }
		//for(int i=127;i>=0;i--)if(a[i]!=0){mx=i;break;}
		//update next max
	}
	
	cout<<ans<<endl;
}