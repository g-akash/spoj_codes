#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class barrier
{
public:
	unsigned long long int s,d;
};

bool comp(barrier p, barrier q)
{
	if(p.s<=q.s)return true;
	return false;
}

int main()
{
	int n;
	cin>>n;
	vector<barrier> b;
	b.resize(n);
	unsigned long long int var;
	for(int i=0;i<n;i++)cin>>b[i].s>>var>>b[i].d;
		sort(b.begin(),b.end(),comp);
		for(int i=1;i<n;i++)
		{
			if(b[i].s<=b[i-1].s+b[i-1].d&&b[i].s+b[i].d>b[i-1].s+b[i-1].d)
			{
				var=(b[i-1].s+b[i-1].d)-b[i].s;
				b[i].s+=(var+1);
				b[i].d-=(var+1);
			}
			else if(b[i].s<=b[i-1].s+b[i-1].d&&b[i].s+b[i].d<=b[i-1].s+b[i-1].d)
			{
				var=(b[i-1].s+b[i-1].d)-b[i].s;
				b[i].s+=(var+1);
				b[i].d=-1;
			}
		}
		unsigned long long int ans=0;
		for(int i=0;i<n;i++)ans+=(b[i].d+1);
			cout<<ans<<endl;

}