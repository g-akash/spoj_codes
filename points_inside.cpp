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


class point
{
public:
	ll x,y;
	point()
	{

	}
	point(ll a, ll b)
	{
		x=a;
		y=b;
	}
};


vector<point> vec;
int n;
int s1,s2;
ll mxy=-1000000001;


int get_pos(int x)
{
	return (x+1)%n;
}

int get_neg(int x)
{
	if(x>0)return x-1;
	else return (x-1)+n;
}


ll get_ceil(double p)
{
	double intprt;
	if(modf(p,&intprt)==0.0)
	{
		return (ll)(p+1);
	}
	else
		return (ll)(ceil(p));
}

ll get_if(double p)
{
	double intprt;
	if(modf(p,&intprt)==0.0)
	{
		return (ll)(p-1);
	}
	else
		return (ll)(floor(p));
}


bool inters(int &b1, int &e1, int &b2, int &e2, int &sy)
{
	bool ans = true;
	//cout<<b1<<" "<<e1<<" "<<b2<<" "<<e2<<endl;
	while(sy>vec[e1].y&&e1!=b2)
	{
		//ans = false;
		e1 = get_pos(e1);
		b1 = get_pos(b1);
	}
	if(e1==b2)return false;
	while(sy>vec[e2].y&&e2!=b1)
	{
		//ans = false;
		e2 = get_neg(e2);
		b2 = get_neg(b2);
	}
	if(e2==b1)return false;
	if(vec[b1].y==sy||sy==vec[b2].y)return false;
	//cout<<b1<<" "<<e1<<" "<<b2<<" "<<e2<<endl;
	s1 = 1; s2 = 0;
	int a = sy, b = min(vec[e1].y,vec[e2].y);
	ll md=a;
	while(s2<s1)
	{
		
		ll x1 = vec[b1].x, x2 = vec[e1].x;
		ll y1 = vec[b1].y, y2 = vec[e1].y;

		if(vec[e1].x==vec[b1].x)
		{
			s1 = vec[e1].x+1;
		}
		else
		{
		 	double tmp = ((double(x2)-double(x1))/(double(y2)-double(y1)))*double(md-y1)+double(x1);
			//cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<tmp<<" printing tmp "<<sy<<endl;
			s1 = get_ceil(tmp);
		}
		x1 = vec[b2].x; x2 = vec[e2].x;
		y1 = vec[b2].y; y2 = vec[e2].y;
		if(vec[e2].x==vec[b2].x)
		{
			s2 = vec[e2].x-1;
		}
		else
		{
			double tmp = ((double(x2)-double(x1))/(double(y2)-double(y1)))*double(md-y1)+double(x1);
			s2 = get_if(tmp);
		}

		if(s2>=s1)b=md;
		else a=md;
		sy = md;
		md = (a+b)/2;
		if(b-a<=1)break;
	}
	//sy = md;
	return true;


	
}


void do_work()
{
	int anss = 0;
	for(int i=0;i<n-1;i++)
	{
		if(vec[i+1].y<vec[i].y)
		{
			anss=i+1;
		}
		else if(vec[i+1].y==vec[i].y&&vec[i+1].x<vec[i].x)
		{
			anss=i+1;
		}
	}
	if(vec[0].y<vec[n-1].y)
		{
			anss=0;
		}
		else if(vec[0].y==vec[n-1].y&&vec[0].x<vec[n-1].x)
		{
			anss=0;
		}

	int b1=anss,b2=anss;
	//cout<<anss<<endl;
	//cout<<vec[anss].x<<" "<<vec[anss].y<<endl;
	int e1 = get_pos(b1);
	int e2 = get_neg(b2);
	vector<point> ans;
	int sy = vec[b1].y+1;
	int count = 0;
	int lim = n/10;
	while(count<lim&&inters(b1,e1,b2,e2,sy))
	{
		//cout<<s1<<" "<<s2<<" "<<sy<<endl;
		if(sy<mxy)
		{
			for(int i=s1;i<=s2&&count<lim;i++)
			{
				point p((ll)i,(ll)sy);
				ans.push_back(p);
				count+=1;
			}
		}
		else break;
		if(count>=lim)break;
		sy+=1;
	}
	if(count<lim)
	{
		cout<<-1<<endl;
	}
	else
	{
		//cout<<ans.size()<<endl;
		foi(lim)
		{
			printf("%lld %lld\n",ans[i].x,ans[i].y);
		}
	}
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		
		cin>>n;
		vec.resize(n);
		ll a,b;
		mxy = -1000000001;
		foi(n)
		{
			scanf("%lld %lld",&a,&b);
			mxy = max(mxy,b);
			point p(a,b);
			vec[n-i-1]=p;
		}
		//reverse(vec.begin(),vec.end());
		do_work();

	}
}