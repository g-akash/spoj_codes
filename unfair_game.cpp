#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		unsigned long long int n,k;
		cin>>n>>k;
		unsigned long long int max_val=(k*(k+1))/2;
		if(max_val<n)cout<<"-1"<<endl;
		else
		{
			unsigned long long int to=max_val-n;
			to*=2;
			to=(unsigned long long int)sqrt(to);
			//cout<<to<<endl;
			if(to*(to+1)==2*(max_val-n))cout<<to<<endl;
			else if((to+1)*(to+2)==2*(max_val-n)) cout<<to+1<<endl;
			else if(to*(to+1)>2*(max_val-n))cout<<to-1<<endl;
			else if((to+1)*(to+2)>2*(max_val-n))cout<<to<<endl;
		}
	}
}
