#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class person
{
	public:
	unsigned long long int m,s;
};

bool comp(person p, person q)
{
	if(p.m<=q.m)return true;
	return false;
}

int main()
{
	int n;
	unsigned long long int d;
	cin>>n>>d;
	vector<person> v;
	v.resize(n);
	for(int i=0;i<n;i++)cin>>v[i].m>>v[i].s;
	sort(v.begin(),v.end(),comp);
	unsigned long long int maxfriendship=v[0].s,min_index=0,var=v[0].s;
	for(int i=1;i<n;i++)
	{
		if(v[i].m>=v[min_index].m+d)
		{
			while(!(v[i].m<v[min_index].m+d))
			{
				var-=v[min_index].s;
				min_index++;
			}
		}
		var+=v[i].s;
		maxfriendship=max(var,maxfriendship);
	}
	cout<<maxfriendship<<endl;
}
	
