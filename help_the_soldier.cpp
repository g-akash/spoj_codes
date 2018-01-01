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


class item
{
public:
	int price,qual;
	item(){
		price = 0;
		qual = 0;
	}
	item(int a, int b)
	{
		price = a;
		qual = b;
	}
};

bool comp(item p, item q)
{
	if(p.price<q.price)return true;
	if(p.price==q.price&&p.qual>q.qual)return true;
	return false;
}
vector<vector<item> > vec(6);
vi cpos(6,0);
int n,t;
int curr_sum = 0;

int get_min_index()
{
	int ans = 0;
	foi(6)
	{
		if(vec[i][cpos[i]].qual<vec[ans][cpos[ans]].qual)ans=i;
	}
	return ans;
}

bool is_possible(int ind)
{
	for(int i=cpos[ind];i<vec[ind].size();i++)
	{
		if(vec[ind][i].qual>vec[ind][cpos[ind]].qual)
		{
			if(curr_sum-vec[ind][cpos[ind]].price+vec[ind][i].price<=t)
			{
				curr_sum = curr_sum-vec[ind][cpos[ind]].price+vec[ind][i].price;
				cpos[ind]=i;
				return true;
			}
		}
	}
	return false;
}

int main()
{
	
	cin>>n>>t;
	
	int a,b,c;
	foi(n)
	{
		cin>>a>>b>>c;
		item it(b,c);
		vec[a-1].pb(it);
	}	
	foi(6)sort(vec[i].begin(),vec[i].end(),comp);
	
	
	foi(6)
	{
		if(vec[i].size()==0)
		{
			cout<<0<<endl;
			return 0;
		}
		curr_sum+=vec[i][0].price;
	}
	if(curr_sum>t)
	{
		cout<<0<<endl;
		return 0;
	}
	while(true)
	{
		int ind = get_min_index();
		if(!is_possible(ind))
		{
			cout<<vec[ind][cpos[ind]].qual<<endl;
			return 0;
		}
	}



}