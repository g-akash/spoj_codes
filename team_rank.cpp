#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class team
{
	public:
	int tem;
	unsigned long long int score;
};

bool comp(team p, team q)
{
	if(p.score>q.score)return true;
	if(p.score==q.score&&p.tem<q.tem)return true;
	return false;
}

int main()
{
	int n;
	cin>>n;
	unsigned long long int a,b;
	vector<team> v;
	v.resize(n);
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		v[i].tem=i+1;
		v[i].score=a*b;
	}
	sort(v.begin(),v.end(),comp);
	cin>>n;
	int x;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		cout<<v[x-1].tem<<endl;
	}
}

