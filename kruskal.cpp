// Minimum Spanning Tree


// Kruskal’s Algorithm

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e4 + 5;
int parent[MAX], nodes, edges;
pair <long long, pair<int, int> > p[MAX];

void initialize()
{
    for(int i = 0;i < MAX;++i){
        parent[i] = i;
        size[i] = 1;
    }
}

int root(int x)
{
    while(parent[x] != x)
    {
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}

void weighted_union(int A,int B)
{
    int root_A = root(A);
    int root_B = root(B);

    if(root_A==root_B)
    	return;

    if(size[root_A] < size[root_B ])
    {
		parent[ root_A ] = parent[root_B];
		size[root_B] += size[root_A];
	}
    else
    {
		parent[ root_B ] = parent[root_A];
		size[root_A] += size[root_B];
	}
}


long long kruskal(pair<long long, pair<int, int> > p[])
{
    int x, y;
    long long cost, minimumCost = 0;
    for(int i = 0;i < edges;++i)
    {

        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;

        // Check if the selected edge is creating a cycle or not
        if(root(x) != root(y))
        {
            minimumCost += cost;
            weighted_union(x, y);
        }    
    }
    return minimumCost;
}

int main()
{
    int x, y;
    long long weight, cost, minimumCost;
    initialize();
    cin >> nodes >> edges;
    for(int i = 0;i < edges;++i)
    {
        cin >> x >> y >> weight;
        p[i] = make_pair(weight, make_pair(x, y));
    }

    // Sort the edges in the ascending order
    sort(p, p + edges);
    minimumCost = kruskal(p);
    cout << minimumCost << endl;
    return 0;
}
