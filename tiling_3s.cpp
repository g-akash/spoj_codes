#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	vector<int> ans;
	ans.resize(31);
	ans[0]=1;
	ans[1]=0;
	ans[2]=3;
	for(int i=3;i<=30;i++)
	{
		int var=0;
		if(i%2==1){ans[i]=0;continue;}
		for(int j=2;j<=i;j++)
		{
			if(j==2)var+=3*ans[i-j];
			else var+=2*ans[i-j];
		}
		ans[i]=var;
	}
	int n;
	cin>>n;
	while(n!=-1)
	{
		cout<<ans[n]<<endl;
		cin>>n;
	}
}
