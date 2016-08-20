#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>



using namespace std;
int mo,n;
unordered_map<int,int> m;
vector<int> c,e;

int best_budget(int budget,int j)
{
	if(j>=n){return 0;}
	if(m.find(j*1000+budget)!=m.end())return m[j*1000+budget];
	int ans1,ans2;
	if(budget-c[j]>=0)
	{
		ans1=best_budget(budget,j+1);
		ans2=best_budget(budget-c[j],j+1);

		if(ans1/1000>(ans2/1000)+e[j])
		{
			m[j*1000+budget]=ans1;
			return ans1;
		}
			else if(ans1/1000==(ans2/1000)+e[j]&&ans1%1000<ans2%1000+c[j])
			{
				m[j*1000+budget]=ans1;
			return ans1;
			}
		else 
		{
			m[j*1000+budget]=ans2+e[j]*1000+c[j];
			return ans2+e[j]*1000+c[j];
		}

	}
	else
	{
		ans1=best_budget(budget,j+1);
		m[j*1000+budget]=ans1;
		return ans1;
	}

}




int main()
{
	
	cin>>mo>>n;
	while(mo!=0||n!=0)
	{
		m.clear();
		c.resize(n);
		e.resize(n);
		for(int i=0;i<n;i++)
		{
			cin>>c[i]>>e[i];
		}

		int ans=best_budget(mo,0);
		cout<<ans%1000<<" "<<ans/1000<<endl;
		cin>>mo>>n;
	}
}