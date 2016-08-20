#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> vec;
	vec.resize(105);
	int var,sum=0;
	for(int i=0;i<5;i++)
	{
		cin>>var;
		vec[var]++;
		sum+=var;
	}
	int maxx=-100;
	for(int i=0;i<105;i++)
	{
		if(vec[i]<=1)continue;
		maxx=max(i*min(vec[i],3),maxx);
	}
	if(maxx>=0)sum-=maxx;
	cout<<sum<<endl;

}