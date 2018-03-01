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
	vi vec(n);
	foi(n)
	{
		cin>>vec[i];
	}
	vi len,nums;
	int curr=vec[0],clen=1;
	for(int i=1;i<vec.size();i++)
	{
		if(vec[i]!=vec[i-1])
		{
			len.pb(clen);
			nums.pb(curr);
			curr=vec[i];
			clen=1;
		} else {
			clen+=1;
		}
	}
	len.pb(clen);
	nums.pb(curr);
	stack<int> lens,vals;
	int ans = 0;
	foi(len.size())
	{
		
		while(true)
		{
			if(lens.empty())
			{
				lens.push(len[i]);
				vals.push(nums[i]);
				break;
			}
			if(lens.top()>=len[i]&&vals.top()!=nums[i])
			{
				ans+=1;
				lens.pop();
				vals.pop();
			} else if(vals.top()==nums[i])
			{
				len[i]+=lens.top();
				lens.pop();
				vals.pop();
			} 
			else 
			{
				lens.push(len[i]);
				vals.push(nums[i]);
				break;
			}
		}
		
	}
	while(!lens.empty())
	{
		lens.pop();
		ans+=1;
	}
	cout<<ans<<endl;
}