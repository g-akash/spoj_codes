#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int t;
	cin>>t;
	int n;
	for(int i=0;i<t;i++)
	{
		int j;
		cin>>n;
		int ans=0;
		for(j=1;j<10000;j++)
		{
			ans+=j;
			if(ans>n)break;

		}
		while(ans>=n){ans-=j;j--;}
		//cout<<ans<<" h "<<j<<endl;
		j+=2;
		int a,b;
		ans=n-ans;
		if(j%2==1){a=1;b=j-1;cout<<"TERM "<<n<<" IS "<<a+(ans-1)<<"/"<<b-(ans-1)<<endl;}
		else {a=j-1;b=1;cout<<"TERM "<<n<<" IS "<<a-(ans-1)<<"/"<<b+(ans-1)<<endl;}


	}
}