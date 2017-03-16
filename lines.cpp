#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

int main()
{
	int n;
	cin>>n;
	while(n!=0)
	{
		vector<double> x,y,slopes;
		x.resize(n);
		y.resize(n);
		for(int i=0;i<n;i++)
		{
			cin>>x[i]>>y[i];
		}
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				double slope=(y[j]-y[i])/(x[j]-x[i]);
				slopes.push_back(slope);
			}
		}
		sort(slopes.begin(),slopes.end());
		int count=1;
		for(int i=1;i<slopes.size();i++)
		{
			if(slopes[i]!=slopes[i-1])count++;
		}
		if(count>=2&&isinf(slopes[0])&&isinf(slopes[slopes.size()-1]))count--;
		cout<<count<<endl;
		cin>>n;
	}
}