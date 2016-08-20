#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    vector<int> vec;
    map<int,int> m;
    int q,type,value,temp,index;
    cin>>q;
    vec.push_back(-1000000000);
    for(int i=0;i<q;i++)
        {
        cin>>type;
        if(type==1)
            {
            cin>>value;
            index=vec.size();
            vec.push_back(value);
            m[vec[index]]=index;
            while(vec[index]<vec[index/2]&&index>1)
                {
                temp=vec[index];
                vec[index]=vec[index/2];
                vec[index/2]=temp;
                m[vec[index/2]]=index/2;
                m[vec[index]]=index;
                index/=2;
               
            }
            
        }
        else if(type==2)
            {
            cin>>value;
            index=m[value];
           temp=vec[vec.size()-1];
            vec[vec.size()-1]=vec[index];
            vec[index]=temp;
            m[vec[index]]=index;

            vec.resize(vec.size()-1);
            while(true)
                {
                if(2*index>=vec.size())break;
                else if(2*index+1>=vec.size())
                {
                    if(vec[2*index]>vec[index])break;
                    temp=vec[index];
                    vec[index]=vec[2*index];
                    vec[2*index]=temp;
                    index*=2;
                    m[vec[index]]=index;
                    m[vec[index/2]]=index/2;
                }
                else 
                {
                    if(vec[index]<vec[2*index]&&vec[index]<vec[2*index+1])break;
                    if(vec[2*index]<=vec[2*index+1])
                    {
                        temp=vec[index];
                        vec[index]=vec[2*index];
                        vec[2*index]=temp;
                        index*=2;
                        m[vec[index]]=index;
                        m[vec[index/2]]=index/2;
                    }
                    else
                    {
                        temp=vec[index];
                        vec[index]=vec[2*index+1];
                        vec[2*index+1]=temp;
                        m[vec[index]]=index;
                        m[vec[2*index+1]]=2*index+1;
                        index=index*2+1;
                        
                    }
                        
                }
            }
        }
        else if(type==3)
            {
            cout<<vec[1]<<endl;
        }
        //for(int j=0;j<vec.size();j++)cout<<vec[j]<<" ";cout<<endl;
    }
    
    return 0;
}
