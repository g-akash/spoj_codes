#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>
#include <map>
#include <queue>
#include <algorithm>
#include <list>

using namespace std;


#define ll long long int
#define umm(x,y) unordered_map<x,y >
#define pb push_back
#define foi(n) for(int i=0;i<n;i++)
#define foj(n) for(int j=0;j<n;j++)
#define foi1(n) for(int i=1;i<=n;i++)
#define vi vector<int>
#define vvi vector<vi >
#define vll vector<ll>
#define vvll vector<vll >
#define si size()

vi vec;

int get_gcd(int a, int b)
{
	if(a==0||b==0)return 0;
	if(a%b==0)return b;
	return get_gcd(b,a%b);
}

int calc_ans()
{
	int ans=0;
	foi(vec.size()-1)
	{
		ans+=get_gcd(vec[i],vec[i+1]);
	}
	return ans;
}

int main()
{
	int n;
	cin>>n;
	vec.resize(n);
	foi(n)cin>>vec[i];
	sort(vec.begin(),vec.end());
	int ans=calc_ans();
	while(next_permutation(vec.begin(),vec.end()))
	{
		ans=max(ans,calc_ans());
	}
	cout<<ans<<endl;
}