#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

int main()
{
	int size_of_graph,vertex1,vertex2;
	cin>>size_of_graph;
	
	vector<vector<int> > v;
	int num_of_edges;
	cin>>num_of_edges;
	v.resize(size_of_graph);
	for(int i=0;i<num_of_edges;i++)
	{
		cin>>vertex1>>vertex2;
		v[vertex1].push_back(vertex2);
		v[vertex2].push_back(vertex1);
	}
	
	
	
	//take input and build a graph with vector representing neighbours
	
	int start,goal;
	vector<int> visited;
	visited.resize(size_of_graph);
	
	cin>>start;
	cin>>goal;
	stack<int> line;
	line.push(start);
	while(!line.empty() && line.top()!=goal)
	{
		int current=line.top();
		line.pop();
		visited[current]=1;
		for(int i=0;i<v[current].size();i++)if(!visited[v[current][i]])line.push(v[current][i]);
	}
	if(line.empty())cout<<"No Path"<<endl;
	else cout<<"there exists a path"<<endl;
}
