#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> fibs;

void doit()
{
	fibs[1]=0;
	fibs[2]=1;
	for(int i=3;i<1100005;i++)
	fibs[i]=(fibs[i-2]+fibs[i-1])%100000;
	return;
}
	

int main()
{
	fibs.resize(1100005);
	doit();
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		vector<int> ans;
		int a,b;
		cin>>a>>b;
		ans.resize(100000);
		cout<<"Case "<<i+1<<":";
		for(int j=a;j<=a+b;j++)
		{
			ans[fibs[j]]++;
		}
		int count=0,cnt=min(100,(b+1));
		for(int j=0;j<100000&&count<cnt;j++)
		{
			for(int k=0;k<ans[j]&&count<cnt;k++){cout<<" "<<j;count++;}
			//count+=ans[j];
		}
		//for(int j=0;j<min(int(ans.size()),100);j++)if(j!=ans.size()-1)cout<<ans[j]<<" ";else cout<<ans[j];
		cout<<endl;
	}
}
	
