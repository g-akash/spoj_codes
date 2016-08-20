#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

using namespace std;
vector<vector< long long int> >v;
 long long int n;
vector<  long long int> vec;
 long long int y;

 long long int ans(int k,int x)
{
    //cout<<k<<" "<<x<<endl;
    //cout<<k<<"alk"<<x<<endl;
    if(x>=n)return 0;
    if(v[k][x]>=0)return v[k][x];
    if(k<=0)
    {
         long long int val=ans(k,x+1);
        val=val | vec[x];
        v[k][x]=val;
        return val;
    }
    long long int a=pow(y,k),b,val1=0;
    for( long long int i=k;i>=0;i--)
    {
        val1=max(val1,ans(k-i,x+1)|(vec[x]*a));
        a/=y;
    }
    
    //int val1=ans(k-1,x+1);int val2=ans(k,x+1);
    //cout<<max(val1,val2)<<"akash1"<<endl;
    //val1=val1 | (vec[x]*y);val2=val2 | vec[x];
    //cout<<max(val1,val2)<<"akash"<<endl;
    v[k][x]=val1;
    return val1;
}   
    

int main()
{
    long long int k;
    
    cin>>n>>k>>y;
    v.resize(k+1);
    for(int i=0;i<=k;i++)v[i].resize(n);
    
    vec.resize(n);
    for(int i=0;i<n;i++){cin>>vec[i];}
    for(int i=0;i<=k;i++)for(int j=0;j<n;j++)v[i][j]=-1;
    
    cout<<ans(k,0)<<endl;
}
