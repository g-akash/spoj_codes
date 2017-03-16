#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long int

bool is_round(ll number)
{
	ll a,b=number%10;
	while(number>=10)number/=10;
	if(number==b)return true;
	return false;
}
vector<int> bit,nums;

void update(int index, int value)
{
	while(index<bit.size())
	{
		bit[index]+=value;
		index+=(index&(-1*index));
	}
}
int calculate(int index)
{
	int sum=0;
	while(index>0)
	{
		sum+=bit[index];
		index-=(index&(-1*index));
	}
	return sum;
}

int main()
{
	
	int n,q;
	cin>>n>>q;
	int var=1;
	while(var<=n)
	{
		var*=2;
	}
	bit.resize(var);
	nums.resize(var);
	ll temp;
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		if(is_round(temp))
		{
			if(nums[i+1]!=1)update(i+1,1);
			nums[i+1]=1;
		}
		else
		{
			if(nums[i+1]!=0)
			{
				update(i+1,-1);
				nums[i+1]=0;
			}
		}
	}
	for(int i=0;i<q;i++)
	{
		int typ,l;
		ll r;
		cin>>typ>>l>>r;
		if(typ==1)
		{
			int ans=0;
			ans+=calculate(r);
			if(l!=1)ans-=calculate(l-1);
			cout<<ans<<endl;
		}
		else
		{
			temp = r;
			if(is_round(temp))
			{
				if(nums[l]!=1)update(l,1);
				nums[l]=1;
			}
			else
			{
				if(nums[l]==1)
				{
					update(l,-1);
					nums[l]=0;
				}
			}
		}
	}
}