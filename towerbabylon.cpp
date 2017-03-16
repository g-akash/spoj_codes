#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<string>

using namespace std;

class box
{
	public:
	int x,y,h;
};
vector<box> v;
unordered_map<string, int> m;

bool comp(box p, box q)
{
	if(p.x>q.x)return true;
	else if(p.x==q.x&&p.y>=q.y)return true;
	return false;
}

int doit(int i, int x, int y)
{
	string s=to_string(x)+"#"+to_string(y);
	if(m.find(s)!=m.end())return m[s];
	if(i>=v.size())return 0;
	int a,b;
	a=doit(i+1,x,y);
	if(v[i].x<x&&v[i].y<y){b=doit(i+1,v[i].x,v[i].y)+v[i].h;}
	else b=a;
	if(a>b)m[s]=a;
	else m[s]=b;
	return m[s];
}


int main()
{
	int n;
	box b;
	cin>>n;
	int d,e,f,x,y,z;
	while(n!=0){
		v.resize(0);
		m.clear();
	for(int i=0;i<n;i++)
	{
		
		cin>>d>>e>>f;
		if(d>=e){x=d;y=e;z=f;}
		else {x=e;y=d;z=f;}
		b.x=x;b.y=y;b.h=z;
		v.push_back(b);
		if(d>=f){x=d;y=f;z=e;}
		else {x=f;y=d;z=e;}
		b.x=x;b.y=y;b.h=z;
		v.push_back(b);
		if(e>=f){x=e;y=f;z=d;}
		else {x=f;y=e;z=d;}
		b.x=x;b.y=y;b.h=z;
		v.push_back(b);
	}
	sort(v.begin(),v.end(),comp);
	cout<<doit(0, 1000000,1000000)<<endl;
	cin>>n;
}
}
		
	
