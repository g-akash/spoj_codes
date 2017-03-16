#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

int main()
{
	int e,f,s,m,e1,f1,s1,m1;
	cin>>e>>f>>s>>m>>e1>>f1>>s1>>m1;
	while(e!=-1&&f!=-1&&s!=-1&&m!=-1&&e1!=-1&&f1!=-1&&s1!=-1&&m1!=-1)
	{

		int a,b,c,d;
		a=e/e1;
		while(a*e1>e)a--;
		while(a*e1<e)a++;
		b=f/f1;
		while(b*f1>f)b--;
		while(b*f1<f)b++;
		c=s/s1;
		while(c*s1>s)c--;
		while(c*s1<s)c++;
		d=m/m1;
		while(d*m1>m)d--;
		while(d*m1<m)d++;
		int ans=max(a,max(b,max(c,d)));
		cout<<ans*e1-e<<" "<<ans*f1-f<<" "<<ans*s1-s<<" "<<ans*m1-m<<endl;
		cin>>e>>f>>s>>m>>e1>>f1>>s1>>m1;

	}
}