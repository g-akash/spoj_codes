#include <iostream>
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
#define vi vector<int>
#define vvi vector<vi >
#define vll vector<ll>
#define vvll vector<vll >
#define si size()


class circle{
public:
	int radius,pos;
	int x,y;
};


bool comppos(circle p, circle q)
{
	if(p.pos<q.pos)return true;
	return false;
}

bool comprad(circle p, circle q)
{
	if(p.radius<q.radius)return true;
	return false;
}



int main()
{
	int n;
	cin>>n;
	vi w(n);
	vector<circle> vec(n);
	foi(n)
	{
		cin>>vec[i].radius>>w[i];
		vec[i].pos=i;
	}
	sort(vec.begin(),vec.end(),comprad);
	int curr=0,currl=-vec[0].radius;
	foi(n)
	{
		if(i%2==0)
		{
			curr+=vec[i].radius;
			//cout<<curr<<" "<<0<<endl;
			vec[i].x=curr;
			vec[i].y=0;
		
			curr+=vec[i].radius;
		}
		else
		{
			currl-=vec[i].radius;
			vec[i].x=currl;
			vec[i].y=0;
			currl-=vec[i].radius;

		}
	}
	sort(vec.begin(),vec.end(),comppos);
	foi(n)
	{
		cout<<vec[i].x<<" "<<vec[i].y<<endl;
	}
}