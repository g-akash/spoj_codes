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
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<string> vec(n);
		foi(n)cin>>vec[i];
		vi nums(1);
		int var;
		int m;
		cin>>m;
		cin>>nums[0];
		string ans = "";
		ans+=string(1,char(nums[0]%128));
		for(int i=1;i<m;i++)
		{
			cin>>var;
			nums.pb(var);
			var-=nums[i-1];
			ans+=string(1,char(var%128));
		}
		string ansp = "Sorry";
		//cout<<ans<<endl;
		foi(n)
		{
			if(vec[i]==ans)
			{
				ansp="Voila";
			}
		}
		cout<<ansp<<endl;

	}
}