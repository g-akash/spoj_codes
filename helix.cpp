#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define lint long long int

int main()
{
	lint n,m;
	cin>>n;
	while(n!=0)
	{
		vector<lint> v1,v2;
		v1.resize(n);
		for(lint i=0;i<n;i++)cin>>v1[i];
			cin>>m;
		v2.resize(m);
		for(lint i=0;i<m;i++)cin>>v2[i];
		vector<lint> i1,i2;
		lint x1=0,x2=0,c1=0,c2=0,ans=0;;
		while(x1<n||x2<m)
		{
			if(x1==n){c2+=v2[x2];x2++;}
			else if(x2==m){c1+=v1[x1];x1++;}
			else
			{
				if(v1[x1]==v2[x2]){c1+=v1[x1];c2+=v2[x2];ans+=max(c1,c2);c1=0;c2=0;x1++;x2++;}
				else if(v1[x1]<v2[x2]){c1+=v1[x1];x1++;}
				else {c2+=v2[x2];x2++;}
			}
		}
		ans+=max(c1,c2);
		cout<<ans<<endl;
		cin>>n;
	}
		
}