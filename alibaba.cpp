#include<iostream>
#include<algorithm>

using namespace std;


class tres
{
public:
	int dist,tim;
};

int main()
{
	int k;
	cin>>k;
	for(int i=0;i<k;i++)
	{
		int n;
		cin>>n;
		vector<tres> vec;
		vec.resize(n);
		for(int i=0;i<n;i++)
		{
			cin>>vec[i].dist>>vec[i].tim;
		}
		sort(vec.begin(),vec.end(),comp);
		
	}
}