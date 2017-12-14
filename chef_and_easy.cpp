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

vector<umm(int,int) > mps(1000005);


void do_work()
{
	vi tmp(1000005);
	for(int i=2;i<1000005;i++)
	{
		if(tmp[i]==1)continue;
		mps[i][i]=1;
		//cout<<i<<endl;
		for(int j=2*i;j<1000005;j+=i)
		{
			int var = j,cnt=0;
			tmp[j]=1;
			//if(j==8&&i==2)cout<<var<<" "<<var%i<<" "<<endl;
			while(var%i==0)
			{
				var/=i;
				cnt+=1;
			}
			//if(j==8&&i==2)cout<<"kk "<<cnt<<endl;
			mps[j][i]=cnt;
		}
	}

}


int main()
{
	do_work();
	//cout<<mps[8][2]<<endl;
	int t;
	cin>>t;
	while(t--)
	{
		vi ans(1000005,0);
		int n,var;
		cin>>n;
		foi(n)
		{
			cin>>var;
			//cout<<"var "<<var<<" ";
			umm(int,int)::iterator it = mps[var].begin();
			while(it!=mps[var].end())
			{
				ans[it->first]=max(ans[it->first],it->second);
				//cout<<it->first<<" "<<ans[it->first]<<" ";
				it++;
			}
			//cout<<endl;
		}
		int fin_ans=0;
		foi(1000005)
		{
			fin_ans+=ans[i];
		}
		cout<<fin_ans<<endl;

	}

}