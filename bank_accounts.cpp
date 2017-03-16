#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class acc{

public:
	int a,b,c,d,e,f;
	bool operator ==(acc x)
	{
		if(a==x.a&&b==x.b&&c==x.c&&d==x.d&&e==x.e&&f==x.f)return true;
		return false;
	}
};

void print(acc x, int c)
{
	cout<<x.a<<" "<<x.b<<" "<<x.c<<" "<<x.d<<" "<<x.e<<" "<<x.f<<" "<<c<<endl;
	return;

	
}

bool comp(acc a, acc b)
{
	if(a.a<b.a)return true;
	if(a.a>b.a)return false;
	if(a.b<b.b)return true;
	if(a.b>b.b)return false;
	if(a.c<b.c)return true;
	if(a.c>b.c)return false;
	if(a.d<b.d)return true;
	if(a.d>b.d)return false;
	if(a.e<b.e)return true;
	if(a.e>b.e)return false;
	if(a.f<b.f)return true;
	if(a.f>b.f)return false;
	return false;
}

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		vector<acc> v;
		int n;
		cin>>n;
		v.resize(n);
		for(int i=0;i<n;i++)cin>>v[i].a>>v[i].b>>v[i].c>>v[i].d>>v[i].e>>v[i].f;
			sort(v.begin(),v.end(),comp);
		if(n>0){
		int cnt=1;
		for(int i=1;i<n;i++)
		{
			if(v[i]==v[i-1])cnt++;
			else
			{
				print(v[i-1],cnt);
				cnt=1;
			}

		}
		print(v[v.size()-1],cnt);
			cout<<endl;
		}
	}
	
}