/*
    author: monsur_riaz
    created: 2024-03-31 22:30:31"

    // dijkstra algorithm naive version implementation
    // Max vertex/node 100
    // Max node's value (n-1)
*/

#include <bits/stdc++.h>
using namespace std;
const int N = 100;
vector<pair<int, int>> adj[N];
int dis[N];

void dijkstra(int source)
{
    queue<pair<int, int>> q;
    q.push({source, 0});
    dis[source] = 0;

    while(!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        int node = par.first;
        int cost = par.second;

        for(pair<int, int> child : adj[node])
        {
            int childNode = child.first;
            int childCost = child.second;
            if(cost+childCost < dis[childNode])
            {
                dis[childNode] = cost + childCost;
                q.push({childNode, cost+childCost});
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b, d;
        cin >> a >> b >> d;
        adj[a].push_back({b, d});
        adj[b].push_back({a, d});
    }
    for(int i=0; i<n; i++)
    {
        dis[i] = INT_MAX;
    }
    
    dijkstra(0);

    for(int i=0; i<n; i++)
        cout << i << " " << dis[i] << endl;
    return 0;
}
