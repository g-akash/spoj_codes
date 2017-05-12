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
	cin>>n;
	umm(string,int) um;
	foi(n)
	{
		vll vec(3);
		cin>>vec[0]>>vec[1]>>vec[2];
		sort(vec.begin(),vec.end());
		string code = to_string(vec[0])+"#"+to_string(vec[1])+"#"+to_string(vec[2]);
		um[code]+=1;
	}
	umm(string,int)::iterator it = um.begin();
	int ans=0;
	while(it!=um.end())
	{
		if(it->second==1)ans++;
		it++;
	}
	cout<<ans<<endl;
}