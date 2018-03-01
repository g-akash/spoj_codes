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

vi lef,rig;
vi points;
int n;
int m;


int get_ans()
{
	int ans = 0;
	foi(n)
	{
		int x=0,y=m-1;
		int st,ed;
		if(points[0]>=lef[i])
		{
			st=0;
		}
		else if(points[m-1]<lef[i])
		{
			st = m;
		}
		else
		{
			while(y-x>1)
			{
				int mid = (x+y)/2;
				if(points[mid]>=lef[i])y=mid;
				else x = mid;
			}
			st = y;
		}

		if(points[m-1]<=rig[i])
		{
			ed=m-1;
		}
		else if(points[0]>rig[i])
		{
			ed = -1;
		}
		else
		{
			x=0;
			y = m-1;
			while(y-x>1)
			{
				int mid = (x+y)/2;
				if(points[mid]<=rig[i])x=mid;
				else y = mid;
			}
			ed = x;
		}

		if(st<=ed&&st!=m&&ed>=0)
		{
			//cout<<lef[i]<<" "<<rig[i]<<" "<<st<<" "<<ed<<endl;
			if((ed-st+1)%2==1){ans+=1;}
		}
	}
	return ans;

}



int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		
		cin>>n;
		lef.resize(n);
		rig.resize(n);
		foi(n)cin>>lef[i]>>rig[i];
		int q;
		cin>>q;
		foi(q)
		{
			
			cin>>m;
			points.resize(m);
			foj(m)
			{
				cin>>points[j];
			}
			sort(points.begin(),points.end());
			int ans = get_ans();
			cout<<ans<<endl;
		}


	}
}