#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<unsigned int> v;
vector<unsigned int> sums;
vector<vector<unsigned int> > ans;

unsigned int retrive(int i, int j)
{
	if(j<i)return 0;
	if(i==0)return sums[j];
	return sums[j]-sums[i-1];
}

unsigned int valu(int i, int j)
{
	//cout<<i<<" "<<j<<endl;
	unsigned int ansi=0;
	if(j<i)return 0;
	//if(j==i)return v[i];
	if(ans[i][j]>0)return ans[i][j];
	else {
		
		for(int k=0;k<j-i+1;k++)
		{
			ansi=max(ansi,v[j]*(k+1)+valu(i,k+i-1)+valu(k+i,j-1)+retrive(k+i,j-1)*(k+1));
			cout<<i<<" "<<j<<" "<<k<<" "<<v[j]*(k+1)<<" "<<(i,k+i-1)<<" "<<valu(k+i,j-1)<<" "<<retrive(k+i,j-1)*(k+1)<<endl;

		}
		ans[i][j]=ansi;
	}
	cout<<i<<" "<<j<<" "<<ansi<<endl;
	return ansi;
}


int main()
{
	int n;
	cin>>n;
	v.resize(n);
	sums.resize(n);
	cin>>v[0];
	sums[0]=v[0];
	for(int i=1;i<n;i++){cin>>v[i];sums[i]=sums[i-1]+v[i];}
	ans.resize(n);
	for(int i=0;i<n;i++)ans[i].resize(n);
	cout<<valu(0,n-1)<<endl;


}