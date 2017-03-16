#include<iostream>
#include<algorithm>
 
using namespace std;
 
int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int ans=0,n;
		cin>>n;
		if(n==3){cout<<3<<endl;continue;}
		while(n>4)
		{
			//
			if(n%2==0){n=(n+2)/2;ans++;}
			else
			{
				n=(n+3)/2;ans++;
			}
			if(n%2==1)n--;
		}
		if(n==4)
		ans+=3;
	else ans+=2;
		cout<<ans<<endl;
	}
} 