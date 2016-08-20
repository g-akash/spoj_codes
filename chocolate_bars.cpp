#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int m,n;
		cin>>m>>n;
		vector<int> v1,v2;
		v1.resize(m-1);
		v2.resize(n-1);
		for(int j=0;j<m-1;j++)cin>>v1[j];
		for(int j=0;j<n-1;j++)cin>>v2[j];
		sort(v1.begin(),v1.end());
		sort(v2.begin(),v2.end());
		int cnt=0,tot=0,x=1,y=1,z=m-2,w=n-2;
		while(cnt<m+n)
		{
			if(z>=0&&w>=0)
			{
				if(v1[z]>v2[w]){tot+=v1[z]*x;z--;y++;}
				else {tot+=v2[w]*y;w--;x++;}

			}
			else if(z<0&&w>=0)
			{
				tot+=v2[w]*y;w--;x++;
			}
			else if(z>=0&&w<0)
			{
				tot+=v1[z]*x;z--;y++;
			}

			cnt++;
		}
		cout<<tot<<endl;
	}
}