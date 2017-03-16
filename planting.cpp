#include<iostream>
#include<vector>
#include<algorithm>



using namespace std;

#define ll long long int

ll hcf(ll x, ll y)
{
	if(x%y==0)return y;
	else return hcf(y,x%y);
}


int main()
{
	int t;
	cin>>t;
	ll count=0,ans=1,mnn=2000000000,mxx=-10000;
	//cin>>vex;
	vector<ll> var;
	var.resize(t);
	for(int i=0;i<t;i++)cin>>var[i];
	sort(var.begin(),var.end());
	for(int i=1;i<t;i++)
	{
		//cin>>var;
		if(i==1)ans=var[i]-var[i-1];
		else
		ans=hcf(ans,var[i]-var[i-1]);
		//mxx=max(mxx,var);
		
				count++;
	}
	//cout<<ans<<endl;
	cout<<(var[t-1]-var[0])/ans-count<<endl;
}
		
	
