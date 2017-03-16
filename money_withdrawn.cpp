#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

#define mult *100000000000
#define ll long long int
unordered_map<ll,ll> um;
vector<ll> vec;

ll calc_max(ll sum, ll loc)
{
	
	if(loc<0)return 0;
	if(sum<=0)return 0;
	if(um.find(sum)!=um.end())return um[sum];
	if(sum<vec[loc]){ll a=calc_max(sum,loc-1);um[sum]=a;return a;}
	ll a=1+calc_max(sum%vec[loc],loc-1),b=calc_max(vec[loc]-1,loc-1);
	a=max(a,b);
	um[sum]=a;
	return a;
}

int main()
{
	int t;
	cin>>t;
	for(int test=0;test<t;test++)
	{
		int n;
		cin>>n;
		ll sum=0;
		vec.resize(n);
		um.clear();
		for(int i=0;i<n;i++)
		{
			cin>>vec[i];
			sum+=vec[i];
			um[vec[i]]=1;
		}
		int count=0;
		ll var=1;
		while(var<=vec[n-1])
		{
			//int a=*upper_bound(vec.begin(),vec.end(),var),b=*lower_bound(vec.begin(),vec.end(),var);
			vector<ll>::iterator a,b;
			a=upper_bound(vec.begin(),vec.end(),var);b=lower_bound(vec.begin(),vec.end(),var);
			if(*a==var){count++;var*=2;}
			else if(b!=vec.end()) {count++;var=2*(*b);}
		}
		//cout<<count<<endl;
		//sort(vec.begin(),vec.end());
		cout<<"Case #"<<test+1<<": "<<count<<endl;
	}
}