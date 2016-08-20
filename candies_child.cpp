#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define ull long long int

int main()
{
	ull m,n;
	ull var,sum=0;
	vector<ull> vec;
	cin>>m>>n;
	vec.resize(n);
	for(int i=0;i<n;i++)
	{
		cin>>vec[i];
		sum+=vec[i];
	}
	//cout<<"mxx"<<endl;
	sort(vec.begin(),vec.end());
	sum=sum-m;
	ull a,b;
	//a=sum/n;
	//b=sum%n;
	//ull ans=(b*(a+1)*(a+1)+(n-b)*(a*a));
	ull ans=0;
	ull mxx=0-1;
	//cout<<mxx+1<<endl;
	for(ull i=0;i<n;i++)
	{
		if(vec[i]*(n-i)<sum){ans+=vec[i]*vec[i];sum-=vec[i];}
		else{a=sum/(n-i);ans=ans+a*a;sum=sum-a;}
	}
	//cout<<mxx<<endl;
	cout<<ans<<endl;
	return 0;
}