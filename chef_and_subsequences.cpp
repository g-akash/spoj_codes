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




int main()
{
	int n;
	ull k;
	cin>>n>>k;
	mm(ull,ull) subs;
	subs[1]=1;
	ull var;
	vector<ull> vec(n);
	foi(n)
	{
		cin>>vec[i];
	}
	ull ans = 0;
	foi(n)
	{
		//cout<<ans<<endl;
		ull tmp = k/vec[i];
		mm(ull,ull)::iterator it = subs.begin();
		mm(ull,ull) mm1;
		while(it->first<=tmp)
		{
			//cout<<" "<<it->first<<" "<<it->second<<endl;
			ans+=it->second;
			mm1[it->first*vec[i]]=it->second;
			it++;
		}
		
		it=mm1.begin();
		while(it!=mm1.end())
		{
			subs[it->first]+=it->second;
			it++;
		}
	}
	cout<<ans<<endl;
}

