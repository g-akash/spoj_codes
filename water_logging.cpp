#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int max_height=0,max_first,max_last;
	int i;
	int n;
	cin>>n;
	vector<int> heights;
	vector<int> water_level;
	heights.resize(n);
	water_level.resize(n);
	for(i=0;i<n;i++)
	{
		cin>>heights[i];
		if(heights[i]>max_height)max_height=heights[i];
	}
	i=0;
	while(heights[i]<max_height)i++;
	max_first=i;
	i=n-1;
	while(heights[i]<max_height)i--;
	max_last=i;
	int curr_water=0;
	for(i=0;i<=max_first;i++)
	{
		water_level[i]=max(curr_water,heights[i]);
		curr_water=water_level[i];
		}
	for(int i=max_first;i<=max_last;i++)
	{
		water_level[i]=max_height;
	}
	curr_water=0;
	for(int i=n-1;i>=max_last;i--)
	{
		water_level[i]=max(curr_water,heights[i]);
		curr_water=water_level[i];
	}
	int ans=0;
	for(int i=0;i<n;i++)
	{
		ans+=(water_level[i]-heights[i]);
	}
	cout<<ans<<endl;
	//cout<<max_height<<endl;
}
	
