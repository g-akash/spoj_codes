#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n,k,var,sum=0,j;
		vector<int> v,fin;
		cin>>n>>k;
		if(k==0||n<1)
		{
			cout<<-1<<endl;
			continue;
		}
		while(n!=0)
		{
			var=n&0x1;
			v.push_back(var);
			sum+=var;
			n=n>>1;
		}
		fin.resize(v.size());
		//for(j=0;j<v.size();j++)cout<<v[j];
		//cout<<endl;
		sum+=(1-v[0]);
		fin[0]=1;
		//cout<<sum<<endl;
		if(sum==k){
		}
		else if(sum<k)
		{
			if(v[0]==1){
				}
			else
			{
				for(j=1;j<v.size()&&v[j]==0&&sum<=k+1;j++){fin[j]=1;sum+=1;}
				while(v[j]==0)j++;fin[j]=0;
				for(j=j+1;j<v.size();j++)fin[j]=v[j];
			}
			
		}
		else if(sum>k)
		{
			for(j=1;j<v.size()&&sum>k;j++)
			{
			
				sum+=(0-v[j]);
				fin[j]=0;
			}while(j<v.size()){fin[j]=v[j];j++;}
			
		}
		
		
		
		//for(int j=0;j<v.size();j++)cout<<v[j];
		//cout<<endl;
		int ans=0;
		for(int j=0;j<v.size();j++)
		{
			ans+=fin[j]*pow(2,j);
		}
		//reverse(v.begin(),v.end());
		cout<<ans<<endl;
	}
}
