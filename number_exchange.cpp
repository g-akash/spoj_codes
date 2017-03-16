#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>
#include <map>
#include <queue>
#include <algorithm>

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
	int n,m,o=0,e=0,x=1,y=2;
	cin>>n>>m;
	vi vec(n),ex(n);
	foi(n)cin>>vec[i];
	umm(int,int) um,ue,uo;
	foi(n)
	{
		if(um.find(vec[i])!=um.end())
		{
			ex[i]=1;
			continue;
		}
		if(vec[i]%2==0)
		{
			if(e<n/2)
			{
				um[vec[i]]=1;
				e++;
			}
			else ex[i]=1;
		}
		else
		{
			if(o<n/2)
			{
				um[vec[i]]=1;
				o++;
			}
			else ex[i]=1;
		}

	}
	//cout<<e<<" "<<o<<endl;
	int count=0;
	foi(n)
	{
		if(ex[i]!=1)continue;
		count++;
		if(e<n/2)
		{
			while(um.find(y)!=um.end())y+=2;
			vec[i]=y;
			um[y]=1;
			y+=2;
			e++;
		}	
		else
		{
			while(um.find(x)!=um.end())x+=2;
			vec[i]=x;
			um[x]=1;
			x+=2;
			o++;
		}
	}
	if(x-2>m||y-2>m)
	{
		cout<<-1<<endl;
		return 0;
	}
	cout<<count<<endl;
	foi(n)cout<<vec[i]<<" ";cout<<endl;




}