#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		set<int> s;
		set<int>::reverse_iterator it;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)s.insert(i);
		vector<int> v,ans;
		v.resize(n);
		ans.resize(n);
		for(int i=0;i<n;i++)cin>>v[i];
		for(int i=n-1;i>=0;i--)
		{
			it=s.rbegin();
			it=next(it,v[i]);
			//cout<<*it<<endl;
			
			ans[i]=*it;
			s.erase(s.find(*it));
		}
		for(int i=0;i<n;i++)cout<<ans[i]<<" ";
		cout<<endl;
	}
}
