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
		cin>>n;
		if(n<=1){cout<<-1<<endl;continue;}
		int ans=0;
		if(n%7==1){ans+=((n/7)-1);n=((n%7)+7);}
		else{ans+=n/7;n=n%7;}
		if(n%5==1){ans+=((n/5)-1);n=((n%5)+5);}
		else{ans+=n/5;n=n%5;}
		if(n%3==1){ans+=((n/3)-1);n=((n%3)+3);}
		else{ans+=n/3;n=n%3;}
		ans+=n/2;
		cout<<ans<<endl;
	}
}
