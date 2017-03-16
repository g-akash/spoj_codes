#include <iostream>
<<<<<<< HEAD
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
#define foj1(n) for(int j=1;j<=n;j++)
#define vi vector<int>
#define vvi vector<vi >
#define vll vector<ll>
#define vvll vector<vll >
#define si size()

class point
=======
#include <string>
#include <vector>
#include <algorithm>

using namespace  std;

class pos
>>>>>>> 605cad988f52511160a1c156a1f635a23974d531
{
public:
	int x,y;
};

<<<<<<< HEAD

=======
>>>>>>> 605cad988f52511160a1c156a1f635a23974d531
int main()
{
	int n,m;
	cin>>n>>m;
<<<<<<< HEAD
	vector<string> vec(n);
	foi(n)
	{
		cin>>vec[i];
	}
	int ax,ay;
	vector<point> points,x,y;
	point var;
	foi(n)
	{
		foj(m)
		{
			if(vec[i][j]=='*')
			{
				var.x=i+1;
				var.y=j+1;
				points.pb(var);
			}
		}
	}
	if(points.size()>=2000)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	foi1(n)
	{
		x.clear();
		y.clear();
		ax=i;
		bool canbedone=true;
		foj(points.size())
		{
			if(points[j].x==i)x.pb(points[j]);
			else y.pb(points[j]);
		}
		if(y.size()==0)
		{
			cout<<"YES"<<endl;
			cout<<ax<<" "<<1<<endl;
			return 0;
		}
		else
		{
			foj1(y.size()-1)
			{
				if(y[j].y!=y[j-1].y)
				{
					canbedone=false;
					break;
				}
			}
			if(canbedone)
			{
				cout<<"YES"<<endl;
				cout<<ax<<" "<<y[0].y<<endl;
				return 0;
			}
		}

	}
	cout<<"NO"<<endl;
=======
	vector<string> vec;
	vec.resize(n);
	for(int i=0;i<n;i++)
	{
		cin>>vec[i];
	}
	vector<pos> poss;
	pos temp;
	vector<int> ys,xs;
	ys.resize(n);
	xs.resize(m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(vec[i][j]=='*')
			{
				temp.y=i;
				temp.x=j;
				poss.push_back(temp);
				xs[j]++;
				ys[i]++;
			}
		}
	}
	int cx=0,cy=0,xp,yp;
	for(int i=0;i<n;i++)
	{
		if(ys[i]>cy){cy=ys[i];yp=i;}
	}
	for(int i=0;i<m;i++)
	{
		if(xs[i]>cx){cx=xs[i];xp=i;}
	}
	if(poss.size()==0)
	{
		cout<<"YES"<<endl;
		cout<<1<<" "<<1<<endl;
	}
	else if(poss.size()==1)
	{
		cout<<"YES"<<endl;
		cout<<poss[0].y+1<<" "<<poss[0].x+1<<endl;	
	}
	else if(poss.size()==2)
	{
		cout<<"YES"<<endl;
		cout<<poss[0].y+1<<" "<<poss[1].x+1<<endl;	
	}
	//int cx=xs[m-1],cy=ys[n-1];
	else
	{
		cx=xp;
	cy=yp;
	//cout<<cx<<cy<<endl;
	bool dont=true;
	vector<int> tpo,tpx;
	for(int i=0;i<poss.size();i++)
	{
		if(poss[i].x!=cx){tpo.push_back(poss[i].y);}
		if(poss[i].y!=cy){tpx.push_back(poss[i].x);}
	}
	sort(tpo.begin(),tpo.end());
	sort(tpx.begin(),tpx.end());
	if(tpo.size()!=0&&tpx.size()!=0)
	{
		if(tpo[0]!=tpo[tpo.size()-1]&&tpx[0]!=tpx[tpx.size()-1])dont=false;
	}
	if(dont)cout<<"YES"<<endl<<cy+1<<" "<<cx+1<<endl;
	else cout<<"NO"<<endl;
}
	
>>>>>>> 605cad988f52511160a1c156a1f635a23974d531

}