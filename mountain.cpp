#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	cin>>n;
	long long int h;
	cin>>h;
	vector<long long int> climb;
	climb.resize(n);
	int i;
	for(i=0;i<n;i++)cin>>climb[i];
	long long int curr=0;
	i=0;
	while(curr<h)
	{
		curr+=climb[i%n];h-=(i+1);
		//cout<<curr<<" "<<h<<endl;
		i++;
		if(curr>=h){break;}
	}
	cout<<i<<endl;
}
	
