#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class data
{
	public:
	int x,y;
	int val;
};

bool comp(data p, data q)
{
	if(p.val<q.val)return true;
	return false;
}

int main()
{
	int n;
	cin>>n;
	vector<data> v;
	vector<int> t;
	t.resize(2*n);
	for(int i=0;i<2*n;i++)t[i]=-1;
	for(int i=1;i<2*n;i++)
	{
		for(int j=0;j<i;j++)
		{
			data d;
			d.x=i;d.y=j;cin>>d.val;
			v.push_back(d);
		}
	}
	
	sort(v.begin(),v.end(),comp);
	for(int i=v.size()-1;i>=0;i--)
	{
		
		if(t[v[i].x]>=0||t[v[i].y]>=0)continue;
		t[v[i].x]=v[i].y;
		t[v[i].y]=v[i].x;
	}
	for(int i=0;i<2*n;i++)cout<<t[i]+1<<" ";
	cout<<endl;
}
	
