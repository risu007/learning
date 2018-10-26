// Topological Sorting

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define N 100001
vector<int>adj[100001];
bool visited[100001];
stack<int>s;

void toposortUtil(int v)
{
	visited[v] = true;
	for(int i=0;i<adj[v].size();i++){
		// This sort function is used for getting the lexicographically smallest topological sort.
		sort(adj[v].begin(),adj[v].end(), greater<int>());

		if(!visited[adj[v][i]])
			toposortUtil(adj[v][i]);
	}

	s.push(v+1);
}

void toposort(int n)
{
	memset(visited,false,sizeof(visited));
	for (int i = 0; i < n; ++i)
	{
		if(!visited[i])
			toposortUtil(i);
	}

	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}
}

int main()
{
	int n,m;
	cin>>n>>m;
	for (int i = 0; i < m; ++i)
	{
		int x,y;
		cin>>x>>y;
		x--;
		y--;
		adj[x].pb(y);
	}
	toposort(n);
	return 0;
}
