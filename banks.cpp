#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stdio.h>

using namespace std;


int main()
{
	int n;
	scanf("%d",&n);
	int t=1;
	while(n!=0)
	{
		vector<vector<int> > vec;
		vec.resize(n+1);
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			vec[i].resize(n+1);
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				//cin>>vec[i][j];
				scanf("%d",&vec[i][j]);
				sum+=vec[i][j];
			}
		}
		vector<int> bal;
		bal.resize(n+1);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				bal[i]-=vec[i][j];
				bal[j]+=vec[i][j];
			}
		}
		int finbal=0;
		for(int i=1;i<=n;i++)if(bal[i]<=0)finbal+=bal[i];
		printf("%d. %d %d\n",t,sum,-1*finbal);
		//cout<<t<<". "<<sum<<" "<<-1*finbal<<endl;
	//cin>>n;
	scanf("%d",&n);
	t++;
	}
}