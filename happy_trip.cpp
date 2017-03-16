#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<iomanip>


using namespace std;

class data
{
	public:
	double x,y,f,happy;
};

int main()
{
	int n;
	cin>>n;
	vector<data> v;
	v.resize(n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i].x>>v[i].y>>v[i].f;
	}
	v[0].happy=v[0].f;
	for(int i=1;i<n;i++)
	{
		double ans=-100000000.0,var,a,b,c,d;
		a=v[i].x;b=v[i].y;
		
		for(int j=0;j<i;j++)
		{
			c=v[j].x;d=v[j].y;
			var=v[j].happy+v[i].f-sqrt((c-a)*(c-a)+(d-b)*(d-b));
			ans=max(ans,var);
		}
		v[i].happy=ans;
	}
	cout<<fixed<<setprecision(6)<<v[n-1].happy<<endl;
}
		
