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


int n,m;
vvi cats,mouse;


class point
{
public:
	int x,y,steps;

	point()
	{
		x=0;
		y=0;
		steps=0;
	}

	point(int a, int b, int c)
	{
		x=a;
		y=b;
		steps=c;
	}
	void make_point(int a, int b, int c)
	{
		x=a;
		y=b;
		steps=c;
		return;
	}
};

int main()
{
	cin>>n>>m;
	cats.resize(n);
	mouse.resize(n);
	foi(n)
	{
		cats[i].resize(n);
		mouse[i].resize(n);
	}
	int t;
	cin>>t;
	while(t--)
	{
		foi(n)
		{
			foj(m)
			{
				cats[i][j]=10000000;
				mouse[i][j]=10000000;
			}
		}
		int a,b,c,d,e,f,d1,d2;
		cin>>d1>>d2>>c>>d>>e>>f;
		d1--;d2--;c--;d--;e--;f--;
		//cats[c][d]=0;
		//cats[e][f]=0;
		point p1(c,d,0), p2(e,f,0);
		queue<point> q;
		q.push(p1);
		q.push(p2);
		while(!q.empty())
		{
			p1 = q.front();
			q.pop();
			a=p1.x;
			b=p1.y;
			//cout<<a<<" "<<b<<endl;
			if(cats[a][b]>p1.steps)
			{
				cats[a][b]=p1.steps;
				if(a>0)
				{
					p2.make_point(a-1,b,p1.steps+1);
					q.push(p2);
				}
				if(a<n-1)
				{
					p2.make_point(a+1,b,p1.steps+1);
					q.push(p2);
				}
				if(b>0)
				{
					p2.make_point(a,b-1,p1.steps+1);
					q.push(p2);
				}
				if(b<m-1)
				{
					p2.make_point(a,b+1,p1.steps+1);
					q.push(p2);
				}
			}
			else continue;
		}
		p1.make_point(d1,d2,0);
		
		q.push(p1);
		bool ans=false;
		while(!q.empty())
		{
			p1 = q.front();
			q.pop();
			a=p1.x;
			b=p1.y;
			if(mouse[a][b]>p1.steps)
			{
				mouse[a][b]=p1.steps;
			}
			else continue;
			//cout<<cats[a][b]<<" "<<mouse[a][b]<<" "<<a<<" "<<b<<endl;
			
			if(mouse[a][b]>=cats[a][b])continue;
			if(a==0||a==n-1||b==0||b==m-1)
			{
				ans=true;
				//cout<<a<<" "<<b<<endl;
				break;
			}
			if(a>0)
			{
				p2.make_point(a-1,b,p1.steps+1);
				q.push(p2);
			}
			if(a<n-1)
			{
				p2.make_point(a+1,b,p1.steps+1);
				q.push(p2);
			}
			if(b>0)
			{
				p2.make_point(a,b-1,p1.steps+1);
				q.push(p2);
			}
			if(b<m-1)
			{
				p2.make_point(a,b+1,p1.steps+1);
				q.push(p2);
			}

		}
		if(ans)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}