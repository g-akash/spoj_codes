#include <iostream>
#include <vector>

using namespace std;


int main()
{
	int n;
	cin>>n;
	vector<int> event,a,b,c;
	event.resize(n+1);
	for(int i=1;i<=n;i++)
	{
		cin>>event[i];
	}
	a.resize(n+1);
	b.resize(n+1);
	c.resize(n+1);
	a[0]=0;b[0]=0;c[0]=0;
	for(int i=1;i<=n;i++)
	{
		if(event[i]==0)
		{
			a[i]=1000000;
			b[i]=1000000;
			c[i]=min(min(a[i-1]+1,b[i-1]+1),c[i-1]+1);
		}
		else if(event[i]==1)
		{
			b[i]=1000000;
			a[i]=min(c[i-1],b[i-1]);
			c[i]=min(min(a[i-1]+1,b[i-1]+1),c[i-1]+1);
		}
		else if(event[i]==2)
		{
			a[i]=1000000;
			b[i]=min(c[i-1],a[i-1]);
			c[i]=min(min(a[i-1]+1,b[i-1]+1),c[i-1]+1);
		}
		else if(event[i]==3)
		{
			a[i]=min(c[i-1],b[i-1]);
			b[i]=min(c[i-1],a[i-1]);
			c[i]=min(min(a[i-1]+1,b[i-1]+1),c[i-1]+1);
		}
	}
	cout<<min(a[n],min(b[n],c[n]))<<endl;
}