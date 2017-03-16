#include <bits/stdc++.h>

using namespace std;


int main()
{
	int N,K;
	double n,l,v1,v2,k;
	cin>>N>>l>>v1>>v2>>K;
	int trips;
	if(N%K==0)trips=N/K;
	else trips=N/K+1;
	n=double(N);
	k=double(K);
	double ans=0,temp;
	temp=(v1)/(v1+v2);
	ans=(l/v2)*((1.0-pow(temp,trips))/(1.0-temp));
	if(trips>1)
	{
		ans=ans+((l*(v2-v1))/(v2*(v2+v1)))*((1.0-pow(temp,trips-2))/(1.0-temp));
	}
	cout<<ans<<endl;

}