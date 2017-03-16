#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

int main()
{
	int n;
	cin>>n;
	while(n!=-1)
	{
		vector<int> vec;
		vec.resize(n);
		int sum=0;
		for(int i=0;i<n;i++)
		{
			cin>>vec[i];
			sum+=vec[i];
		}
		if(sum%n!=0){cout<<-1<<endl; cin>>n;continue;}
		int ans=0;
		sum/=n;
		int cursum=0;
		for(int i=0;i<n;i++)
		{
			cursum+=vec[i];
			ans=max(abs(sum*(i+1)-cursum),ans);
		}
		cout<<ans<<endl;
		cin>>n;
	}
}