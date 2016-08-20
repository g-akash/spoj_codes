#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;



int main()
{
	unsigned long long int s;
	cin>>s;
	if(s<1500)
	{
		int ans=s+1;
		cout<<ans<<endl;
		for(int i=0;i<ans;i++)
		{
			if(i%2==0)cout<<2<<" ";
			else cout<<3<<" ";
		}
		cout<<endl;
	}
	else
	{
		int num6=1;
		while(s>1000000)
		{
			num6++;s-=1000000;
		}
		if(s==0)
		{
			cout<<num6<<endl;

			for(int i=0;i<num6;i++)cout<<1000000<<" ";
				cout<<endl;

		}
		else if(s==1)
		{
			cout<<num6+1<<endl;
			for(int i=0;i<num6;i++)cout<<1000000<<" ";
				cout<<1<<" ";
			cout<<endl;


		}
		else if(s==2)
		{
			cout<<num6+2<<endl;
			for(int i=0;i<num6;i++)cout<<1000000<<" ";
				cout<<1<<" "<<1<<" ";
			cout<<endl;

		}
		else
		{
			cout<<num6+3<<endl;
			for(int i=0;i<num6;i++)cout<<1000000<<" ";
				cout<<1<<" "<<s-2<<" "<<s-2<<" ";
			cout<<endl;

		}


	}
}