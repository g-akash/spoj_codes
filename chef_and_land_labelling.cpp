#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>

using namespace std;


#define ll long long int
#define ull unsigned ll
#define umm(x,y) unordered_map<x,y >
#define mm(x,y) map<x,y >
#define pb push_back
#define foi(n) for(int i=0;i<n;i++)
#define foj(n) for(int j=0;j<n;j++)
#define foi1(n) for(int i=1;i<=n;i++)
#define foj1(n) for(int j=1;j<=n;j++)
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vi >
#define vvb vector<vb >
#define vll vector<ll>
#define vvll vector<vll >
#define si size()

int n;
vi facs;
vi ones;

void make_facs()
{
	facs.resize(n+1);
	ones.resize(n+1);
	foi(n+1)
	{
		facs[i]=0;
		ones[i]=0;
	}
	foi1(n)
	{
		for(int j=1;j<=n;j++)
		{
			if(j%i==0)
				facs[j]+=1;
			else if(i%j!=0) ones[j]+=1;
			if(i==1)ones[j]+=1;
		}
	}
	return;
}

vvi conds;


int main()
{
	int t;
	
	cin>>t;
	while(t--)
	{
		cin>>n;
		make_facs();
		conds.resize(n);
		foi(n)
		{
			conds[i].resize(1001);
			foj(1001)conds[i][j]=0;
		}
		int var;
		foi(n)
		{
			foj(n)
			{
				cin>>var;
				conds[i][var]+=1;
			}
		}
		vi labels(n);
		foi(n)labels[i]=-1;
		// foi(n)
		// {
		// 	if(conds[i][1]==n-1)
		// 	{
		// 		labels[i]=1;
		// 		//cout<<i<<"imp"<<endl;
		// 		break;
		// 	}
		// }
		for(int i=2;i<=n;i++)
		{
			int fc = facs[i];
			//cout<<facs[i]<<endl;
			//cout<<i<<" "<<ones[i]<<endl;	
			int terms = n/i - 1;
			for(int j=0;j<n;j++)
			{
				if(conds[j][fc]==terms&&labels[j]==-1&&conds[j][1]==ones[i])
				{
					labels[j]=i;
					break;
				}
			}
		}
		foi(n)if(labels[i]!=-1)cout<<labels[i]<<endl;else cout<<1<<endl;

	}
}