#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> ans;

class dat
{
	public:
	int val;
	int big;
	dat()
	{
		val=0;
		big=0;
	}
};

void sorter(vector<dat> nums)
{
	if(nums.size()==1||nums.size()==0)return;
	vector<dat> small,large;
	int pivot=nums[0].val;
	for(int i=1;i<nums.size();i++)
	{
		if(nums[i].val<pivot){small.push_back(nums[i]);ans[pivot]++;if(large.size()>0)large[large.size()-1].big++;}
		else if(nums[i].val>pivot)large.push_back(nums[i]);
	}
	int var=0;
	for(int i=large.size()-1;i>-1;i--){var+=large[i].big;large[i].big=0;ans[large[i].val]+=var;}
	sorter(small);
	sorter(large);
	//cout<<pivot<<" "<<ans[pivot]<<"ho"<<endl;
}
	

int main()
{
	int t;
	cin>>t;
	ans.resize(1000005);
	for(int i=0;i<t;i++)
	{
		int n;
		cin>>n;
		vector<dat> nums;
		nums.resize(n);
		//var.resize(n);
		for(int i=0;i<n;i++){cin>>nums[i].val;}
		for(int i=0;i<1000005;i++)ans[i]=0;
		 sorter(nums);
		 for(int i=0;i<n;i++)cout<<ans[nums[i].val]<<" ";
		 cout<<endl;
	}
}
