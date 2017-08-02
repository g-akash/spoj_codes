#include <iostream>
#include <vector>
//#include <unordered_map>
 
#include <math.h>
//#include <map>
 
#include <algorithm>
#include <stdio.h>
 
using namespace std;
 
 
#define ll long long int
#define ull unsigned ll
#define umm(x,y) unordered_map<x,y >
#define mm(x,y) map<x,y >
#define pb push_back
#define foi(n) for(int i=0;i<n;i++)
#define foj(n) for(int j=0;j<n;j++)
#define foi1(n) for(int i=1;i<=n;i++)
#define foj1(n) for(int j=1;j<=n;j++)
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vi >
#define vvb vector<vb >
#define vll vector<ll>
#define vvll vector<vll >
#define si size()
 
 
 
int n;
int c;
 
 
class edge
{
public:
        int strt,ed,cst;
        edge(int st=-1,int nd=-1, int cost=0)
        {
                strt = st;
                ed = nd;
                cst = cost;
        }
 
        bool operator<(const edge e) const
        {
                if(cst<e.cst)return true;
                if(cst==e.cst&&ed<e.ed)return true;
                return false;
        }
 
};
 
vector<edge> ms;
vi parent;
 
int get_parent(int x)
{
        if(parent[x]==x)return x;
        int par = parent[x];
        int ans = get_parent(par);
        parent[x] = parent[par];
        return ans;
}
 
bool same_parent(int x, int y)
{
        int par1 = get_parent(x);
        int par2 = get_parent(y);
        if(par1==par2)return true;
        parent[par1]=par2;
        return false;
}
 
void make_same(int x, int y)
{
        
        
        return;
}
 
 
int main()
{
        cin>>n;
        parent.resize(n);
        foi(n)parent[i]=i;
        foi(n)
        {
                foj(n)
                {
                        scanf("%d",&c);
                        if(i==0||j==0||i>=j)continue;
                        edge e(i,j,c);
                        ms.pb(e);
                }
        }
        int ans = 0;
        sort(ms.begin(),ms.end());
        foi(ms.size())
        {
                edge e = ms[i];
                int a = e.strt, b = e.ed;
                if(same_parent(a,b))continue;
                ans+=e.cst;
        }
        printf("%d\n",ans);
 
}