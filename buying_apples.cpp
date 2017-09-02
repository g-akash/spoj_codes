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



class pack
{
public:
	int weight,price;
	pack(int a, int b)
	{
		weight = a;
		price = b;
	}
	pack()
	{
		weight = 0;
		price = 0;
	}
};

bool comp(pack p, pack q)
{
	if(p.weight<q.weight)return true;
	else if(p.weight==q.weight&& p.price<q.price)return true;
	return false;
}


vi vec(1000005);
vector<pack> packs(0);

int get_ans(int left,int ind, int weight)
{
	
	if(weight == 0)
	{
		//cout<<"problem"<<endl;
		return 0;
	}
	if(ind>=packs.size())return 100000000;
	if(left<0)return 100000000;
	if(vec[left*10000+ind*100+weight]!=-1)
		{
			
			return vec[left*10000+ind*100+weight];
		}
	int ans1 = 100000000, ans2 = 100000000;
	if(weight>=packs[ind].weight)
	{
		ans1 = get_ans(left-1,ind,weight-packs[ind].weight)+packs[ind].price;
	}
	ans2 = get_ans(left,ind+1,weight);
	ans1 = min(ans1,ans2);
	vec[left*10000+ind*100+weight] = ans1;
	
	return ans1;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k,var;
		cin>>n>>k;
		//cout<<n<<" taking input "<<k<<endl;
		packs.resize(0);
		foi(1000005)vec[i]=-1;
		foi1(k)
		{
			cin>>var;
			if(var!=-1)
			{
				pack p(i,var);
				packs.pb(p);
			}

		}
		sort(packs.begin(),packs.end(),comp);
		//cout<<0<<" calling ans "<<k<<endl;
		int ans = get_ans(n,0,k);
		if(ans>=1000000)cout<<-1<<endl;
		else cout<<ans<<endl;

	}
}