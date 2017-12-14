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
#include <iomanip>

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


class point{
public:
	double x,y;
	int point_num;
};


bool sort_x(point p, point q){
	if(p.y<q.y)return true;
	if(p.y==q.y&&p.x<q.x)return true;
	if(p.y==q.y&&p.x==q.x&&p.point_num<q.point_num)return true;
	return false;
}
bool sort_y(point p, point q){
	if(p.y<q.y)return true;
	if(p.y==q.y&&p.x<q.x)return true;
	if(p.y==q.y&&p.x==q.x&&p.point_num>q.point_num)return true;
	return false;
}

bool sort_num(point p, point q){
	if(p.point_num<q.point_num)return true;
	return false;
}


double cross(point o, point p, point q){
	return (p.x-o.x)*(q.y-o.y)-(q.x-o.x)*(p.y-o.y);
}


umm(ll,bool) um;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		um.clear();
		int n;
		cin>>n;
		vector<point> vec(n);
		int curr=0;
		foi(n){
			cin>>vec[curr].x>>vec[curr].y;
			vec[curr].point_num=i+1;
			ll mval = (ll)vec[curr].x*10000000000+(ll)vec[curr].y;
			//
			if(um.find(mval)==um.end())
			{
				curr++;
			}
			um[mval]=true;;
		}
		if(curr==1)
		{
			cout<<0.00<<endl;
			cout<<1<<endl<<endl;
			continue;
		}
		vec.resize(curr);
		//cout<<curr<<endl;
		sort(vec.begin(),vec.end(),sort_x);
		vector<point> ans(2*n);
		int k = 0;
		//cout<<vec[0].x<<" "<<vec[0].y<<endl;
		for(int i=0;i<vec.size();i++)
		{
			while(k>=2&&cross(ans[k-2],ans[k-1],vec[i])<=0)k--;
			ans[k]=vec[i];
			k++;
		}
		int t = k+1;
		//sort(vec.begin(),vec.end(),sort_y);
		for(int i=vec.size()-2;i>=0;i--)
		{
			while(k>=t&&cross(ans[k-2],ans[k-1],vec[i])<=0)k--;
			ans[k]=vec[i];
			k++;
		}
		double length = 0.0;
		for(int i=0;i<k-1;i++)
		{
			length += sqrt(pow((ans[i+1].x-ans[i].x),2)+pow((ans[i+1].y-ans[i].y),2));
		}
		cout<<fixed<<setprecision(2)<<length<<endl;
		for(int i=0;i<k-1;i++)
		{
			cout<<ans[i].point_num<<" ";
		}
		cout<<endl<<endl;

	}
}