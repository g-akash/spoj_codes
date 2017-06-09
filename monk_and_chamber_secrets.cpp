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


class spider
{
public:
	int pos,power;
};

int main()
{
	int n,x;
	cin>>n>>x;
	queue<spider> q,tmp;
	spider s;
	foi(n)
	{
		cin>>s.power;
		s.pos = i+1;
		q.push(s);
	}
	vi ans;
	foi(x)
	{
		int mxp = -1,pos=-1;
		for(int j=0;j<x&&!q.empty();j++)
		{
			s=q.front();
			q.pop();
			if(s.power>mxp)
			{
				pos=s.pos;
				mxp=s.power;
			}
			if(s.power>0)s.power--;
			tmp.push(s);
		}
		ans.push_back(pos);
		while(!tmp.empty())
		{
			s=tmp.front();
			tmp.pop();
			if(s.pos!=pos)q.push(s);
		}


	}
	foi(ans.size())
	{
		cout<<ans[i]<<" ";
	}
	cout<<endl;


}