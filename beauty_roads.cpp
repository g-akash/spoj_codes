#include <iostream>
#include <vector>

using namespace std;

#define ll long long int

int main()
{
	ll n,k,sum=0,ans=0,var,temp,sumc=0,ansc=0;
	cin>>n>>k;
	vector<ll> vec,caps,mc;
	vec.resize(n);
	caps.resize(n);
	for(int i=0;i<n;i++)
	{
		cin>>vec[i];
		sum+=vec[i];
	}
	for(int i=0;i<n;i++)
	{
		ans+=vec[i]*vec[(i+1)%n];
	}
	//cout<<ans<<endl;
	for(int i=0;i<k;i++)
	{
		cin>>var;
		caps[var-1]=vec[var-1];
		sumc+=caps[var-1];
		sum-=vec[var-1];
		vec[var-1]=0;
		mc.push_back(var);
		
	}
	for(int i=0;i<k;i++)
	{
		var=mc[i];
		int j;
		if(var-2<0)j=var+n-2;
		else j=var-2;
		//cout<<vec[var-1]<<" "<<vec[(var)%n]<<" "<<vec[j]<<endl;
		temp=sum-(vec[var-1]+vec[(var)%n]+vec[j]);
		ans+=(temp*caps[var-1]);
		//cout<<ans<<temp<<" ans"<<endl;
		temp = sumc-(caps[var-1]+caps[(var)%n]+caps[j]);
		ansc+=(temp*caps[var-1]);
	}
	//cout<<ans<<" "<<sumc<<endl;
	cout<<ans+ansc/2<<endl;
	
}