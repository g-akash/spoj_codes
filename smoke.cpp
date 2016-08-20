#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

int main()
{
	int n;
	while(cin>>n)
	{
		vector<int> v;
		v.resize(n);
		for(int i=0;i<n;i++)cin>>v[i];
		vector<vector<int> > smok,mix;
		smok.resize(n);mix.resize(n);
		for(int i=0;i<n;i++)
		{
			smok[i].resize(n);
			mix[i].resize(n);
		}
		for(int i=0;i<n;i++)
		{
			smok[i][i]=0;
			mix[i][i]=v[i];
		}
		int diff=1;
		for(diff=1;diff<n;diff++)
		{
			for(int i=0;i<n-diff;i++)
			{
				int j=i+diff;
				int minsmok=1000000000;
				int minmix;
				for(int k=i+1;k<=j;k++)
				{
					if(smok[i][k-1]+smok[k][j]+mix[i][k-1]*mix[k][j]<minsmok)
					{
						minsmok=smok[i][k-1]+smok[k][j]+mix[i][k-1]*mix[k][j];
						minmix=(mix[i][k-1]+mix[k][j])%100;
					}
				}
				smok[i][j]=minsmok;
				mix[i][j]=minmix;
				//cout<<i<<" "<<j<<endl;
			}

		}
		cout<<smok[0][n-1]<<endl;
	}
}