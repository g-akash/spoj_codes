#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
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


class inc{
public:
	int t,ty;
	char g;
};

bool comp(inc p, inc q)
{
	if(p.t<q.t)return true;
	if(p.t==q.t&&p.ty==0&&q.ty==1)return true;
	return false;
}

int main()
{
	int n;
	cin>>n;
	inc a;
	vector<inc> vec;
	foi(n)
	{
		cin>>a.g>>a.t;
		a.ty=0;
		vec.pb(a);
		cin>>a.t;
		a.ty=1;
		vec.pb(a);
	}
	sort(vec.begin(),vec.end(),comp);
	int ans=0,mn=0,fe=0;
	foi(vec.size()){
		if(vec[i].ty==0){
			if(vec[i].g=='F')fe++;
			else mn++;
		}
		else{
			if(vec[i].g=='F')fe--;
			else mn--;
		}
		ans=max(ans,2*min(fe,mn));
	}
	cout<<ans<<endl;
}