#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>


using namespace std;


#define ll long long int
#define ull unsigned long long int
#define umm(x,y) unordered_map<x,y >
#define pb push_back
#define foi(n) for(int i=0;i<n;i++)
#define foj(n) for(int j=0;j<n;j++)
#define foi1(n) for(int i=1;i<=n;i++)
#define vi vector<int>
#define vvi vector<vi >
#define si size()

class point{
public:
	ll x,y,z;
};

bool compx(point p, point q){
	if(p.x<q.x)return true;
	return false;
}

bool compy(point p, point q){
	if(p.y<q.y)return true;
	return false;
}

bool compz(point p, point q){
	if(p.z<q.z)return true;
	return false;
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<point> vec(n);
		foi(n){
			cin>>vec[i].x>>vec[i].y>>vec[i].z;
		}
		ll ax,ay,az;
		sort(vec.begin(),vec.end(),compx);
		if(n%2==1){
			ax=vec[n/2].x;
		}
		else{
			ax=(vec[n/2].x+vec[n/2-1].x)/2;
		}
		sort(vec.begin(),vec.end(),compy);
		if(n%2==1){
			ay=vec[n/2].y;
		}
		else{
			ay=(vec[n/2].y+vec[n/2-1].y)/2;
		}
		sort(vec.begin(),vec.end(),compz);
		if(n%2==1){
			az=vec[n/2].z;
		}
		else{
			az=(vec[n/2].z+vec[n/2-1].z)/2;
		}
		cout<<ax<<" "<<ay<<" "<<az<<endl;
	}
}