#include<iostream>
#include<vector>
#include<iostream>
#include<math.h>

using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n;
		int ans=0;
		cin>>n;
		n*=n;
		int srt=sqrt(n);
		
		for(int j=1;j<srt;j++)
		{
			if(n%j==0&&n/j<=n/2)
				{
					if((n/j)%2==0)ans+=1;
					if(j%2==0)ans+=1;
				}
			else if(n%j==0&&(n/j)%2==0)ans+=1;
		}
		if(n%srt==0&&srt!=n&&srt%2==0)ans+=1;
		cout<<ans<<endl;
	}
}