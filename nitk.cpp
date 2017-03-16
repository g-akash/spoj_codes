#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n;
		cin>>n;
		vector<int> vec;
		vec.resize(n);
		bool ans=true;
		for(int j=0;j<n;j++)cin>>vec[j];
		for(int j=0;j<n-1;j++){if(vec[j+1]<vec[j])ans=false;vec[j+1]-=vec[j];vec[j]=0;}
		if(vec[vec.size()-1]!=0)ans=false;
		if(ans)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}