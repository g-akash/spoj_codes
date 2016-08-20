#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class pos
{
public:
	int h,w;
};

bool comp1(pos a, pos b)
{
	if(a.w<b.w)return true;
	return false;
}

bool comp2(pos a, pos b)
{
	if(a.h<b.h)return true;
	return false;
}

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int h,w,n,maxh=0,maxw=0;
		cin>>h>>w>>n;
		vector<pos> v1,v2;
		v1.resize(n);
		for(int j=0;j<n;j++)
		{
			cin>>v1[j].h>>v1[j].w;
			
		}
		pos x;
		x.w=0;x.h=0;
		v1.push_back(x);
		x.w=w+1;x.h=h+1;
		v1.push_back(x);
		v2=v1;
		sort(v1.begin(),v1.end(),comp1);
		sort(v2.begin(),v2.end(),comp2);
		int ans=0;
		//if(n==0){cout<<w*h<<endl;continue;}
		for(int j=0;j<n+1;j++)
			maxh=max(maxh,v2[j+1].h-v2[j].h-1);
		for(int j=0;j<n+1;j++)
			maxw=max(maxw,v1[j+1].w-v1[j].w-1);
		//cout<<maxh<<" koko "<<maxw<<endl;
		cout<<maxw*maxh<<endl;
		//cout<<ans<<endl;
	}
}