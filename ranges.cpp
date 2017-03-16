#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<int> v;
	v.resize(n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
	sort(v.begin(),v.end());
	int q;
	cin>>q;
	for(int i=0;i<q;i++)
	{
		int a,b;
		cin>>a>>b;
		vector<int>::iterator it1,it2;
		it1=lower_bound(v.begin(),v.end(),a);
		it2=upper_bound(v.begin(),v.end(),b);
		//cout<<*it1<<" "<<*it2<<endl;
		cout<<it2-it1<<endl;
	}
}
