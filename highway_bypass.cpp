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



vvll inter;
vector<vvll >  visitedV,visitedH,ansV,ansH;
// 1 is for when hori takes value d and 2 is for when ver takes value d
ll a,b,d;



ll get_res(ll a, ll b, ll w, char dir)
{

	// add the visited clause later
	// also store the results
	if(inter[a][b]==0)return 0;
	ll ans=0;
	if(dir=='V')
	{
		if(visitedV[a][b][w]==1)return ansV[a][b][w];
		if(w==0&&ansH[a][b][0]==1)return ansH[a][b][0];
		visitedV[a][b][w]=1;
		if(b-1>=0)
		{
			ll hor=0;
			hor = max(hor,get_res(a,b-1,1,'H'));
			ans+=hor;
		}
		if(a-1>=0&&w+1<=d)
		{
			ll ver = 0;
			ver = max(ver,get_res(a-1,b,w+1,'V'));
			ans+=ver;
		}

		ansV[a][b][w]=ans;
	}
	else
	{
		if(visitedH[a][b][w]==1)return ansH[a][b][w];
		if(w==0&&ansV[a][b][0]==1)return ansV[a][b][0];
		visitedH[a][b][w]=1;
		if(a-1>=0)
		{
			ll ver = 0;
			ver = max(ver,get_res(a-1,b,1,'V'));
			ans+=ver;
		}
		if(b-1>=0&&w+1<=d)
		{
			ll hor = 0;
			hor = max(hor,get_res(a,b-1,w+1,'H'));
			ans+=hor;
		}

		ansH[a][b][w]=ans;

	}
	return ans;
}

int main()
{
	
	cin>>a>>b>>d;
	inter.resize(a);
	visitedV.resize(a);
	visitedH.resize(a);
	ansV.resize(a);
	ansH.resize(a);
	foi(a)
	{
		inter[i].resize(b);
		visitedV[i].resize(b);
		visitedH[i].resize(b);
		ansV[i].resize(b);
		ansH[i].resize(b);
	}
	foi(a)
	{
		foj(b)
		{
			cin>>inter[i][j];
		}
	}

	foi(a)
	{
		foj(b)
		{
			visitedV[i][j].resize(d+1);
			visitedH[i][j].resize(d+1);
			ansV[i][j].resize(d+1);
			ansH[i][j].resize(d+1);
			for(int k=0;k<=d;k++)
			{
				visitedV[i][j][k]=0;
				visitedH[i][j][k]=0;
				ansV[i][j][k]=0;
				ansH[i][j][k]=0;
			}
		}
	}







	foi(d+1)
	{
		visitedH[0][0][i]=1;
		visitedV[0][0][i]=1;
		ansH[0][0][i]=1;
		ansV[0][0][i]=1;
	}
	ll ans1 = get_res(a-1,b-1,0,'V');
	ll ans2 = get_res(a-1,b-1,0,'H');
	cout<<max(ans1,ans2)<<endl;
	
	
}