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



class candidates
{
public:
	int id,vote;
	candidates()
	{
		id = 0;
		vote=0;
	}
};

int c,v;
vvi votes;
vector<candidates> cand;


bool comp(candidates p, candidates q)
{
	if(p.vote>q.vote)return true;
	if(p.vote==q.vote&&p.id<q.id)return true;
	return false;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>c>>v;
		int vote,round=1;
		cand.resize(0);
		cand.resize(c);
		foi(c)
		{
			cand[i].id = i+1;
		}
		votes.clear();
		votes.resize(v);
		foi(v)
		{
			foj(c)
			{
				cin>>vote;
				if(j==0)
				{
					cand[vote-1].vote+=1;
				}
				votes[i].pb(vote);
			}
		}
		sort(cand.begin(),cand.end(),comp);
		if(cand[0].vote*2>v)
		{
			cout<<cand[0].id<<" "<<1<<endl;
		}
		else
		{
			int c1 = cand[0].id;
			int c2 = cand[1].id;
			int v1=0,v2=0;
			foi(v)
			{
				foj(c)
				{
					if(votes[i][j]==c1){v1++;break;}
					else if(votes[i][j]==c2){v2++;break;}
				}
			}
			round = 2;
			if(v1>v2){cout<<c1<<" "<<2<<endl;}
				else
				{
					cout<<c2<<" "<<2<<endl;
				}
		}

	}
}