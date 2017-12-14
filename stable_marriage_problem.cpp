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

vvi wr;
int cw;


bool comp(int p, int q)
{
	if(wr[cw][p]<wr[cw][q])return true;
	return false;
}

bool compp(pair<int,int> p, pair<int,int> q)
{
	if(p.first<q.first)return true;
	return false;
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vvi wp(n);
		vvi mp(n);
		wr.resize(n);
		vi cpm(n);
		vvi cwp(n);
		foi(n)
		{
			wp[i].resize(n);
			mp[i].resize(n);
			wr[i].resize(n);
			cpm[i]=0;
		}
		foi(n)
		{
			cin>>cw;
			foj(n)
			{
				cin>>wp[i][j];
				wp[i][j]-=1;
				wr[i][wp[i][j]]=j;
			}
		}
		foi(n)
		{
			cin>>cw;
			foj(n)
			{
				cin>>mp[i][j];
				mp[i][j]-=1;
			}
		}
		//cout<<"input!!"<<endl;
		bool change=true;
		while(change)
		{
			change=false;
			//cout<<"ll"<<endl;
			foi(n)
			{
				//cout<<cpm[i]<<" "<<mp[i].size()<<endl;
				//cout<<mp[i][cpm[i]]<<endl;
				cwp[mp[i][cpm[i]]].pb(i);
			}
			foi(n)
			{
				cw=i;
				sort(cwp[i].begin(),cwp[i].end(),comp);
				//cout<<i<<endl;
				//foj(cwp[i].size())cout<<cwp[i][j]<<" ";
				//cout<<endl;
			}
			//cout<<i<<endl;

			foi(n)
			{
				if(cwp[i].size()<=1)
				{
					cwp[i].resize(0);
					continue;
				}
				change=true;
				foj1(cwp[i].size()-1)
				{
					cpm[cwp[i][j]]+=1;
				}
				cwp[i].resize(0);
			}
		}
		vector<pair<int,int> > vp;
		foi(n)
		{
			//cout<<cwp[i][0]+1<<" "<<i+1<<endl;
			pair<int,int> p(cwp[i][0]+1,i+1);
			vp.pb(p);
		}
		sort(vp.begin(),vp.end(),compp);
		foi(n)
		{
			cout<<vp[i].first<<" "<<vp[i].second<<endl;
		}

	}
}