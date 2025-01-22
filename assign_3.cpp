#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

class Graph 
{
    int V;  // Number of vertices
    vector<vector<pair<int, int>>> adj;  // Adjacency list to store graph

public:
    Graph(int n) 
    {
        V = n;
        adj.resize(V);
        int u, v, wt;
        while (true) 
        {
            cout << "\nEnter start vertex (-1 to stop): ";
            cin >> u;
            if (u == -1) break;  
            if (u < 0 || u >= V) 
            {
                cout << "Invalid start vertex! Please enter a vertex between 0 and " << V - 1 << ".\n";
                continue;
            }
            cout << "Enter end vertex: ";
            cin >> v;
            if (v < 0 || v >= V) 
            {
                cout << "Invalid end vertex! Please enter a vertex between 0 and " << V - 1 << ".\n";
                continue;
            }
            if (u == v) 
            {
                cout << "Self-loops are not allowed! Please enter different vertices.\n";
                continue;
            }
            cout << "Enter weight: ";
            cin >> wt;
            
            // Add edge to adjacency list (bidirectional) - undirected graph
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
    }

    void printGraph() 
    {
        cout << "\nGraph adjacency list:\n";
        for (int i = 0; i < V; ++i) {
            cout << i << ": ";
            for (auto &it : adj[i]) {
                cout << "(" << it.first << ", " << it.second << ") ";
            }
            cout << endl;
        }
    }

    int primsAlgo() 
    {
        // Min-heap priority queue: (weight, vertex)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> visited(V, false);
        int minCost = 0;

        // Start with vertex 0
        pq.push({0, 0});

        while (!pq.empty()) 
        {
            auto it = pq.top();  // Get minimum weight edge
            int u = it.second;
            int wt = it.first;
            pq.pop();

            if (visited[u]) continue;  // Skip already visited nodes

            visited[u] = true; 
            minCost += wt;  

            // Explore adjacent vertices
            for (auto &it : adj[u]) 
            {
                int v = it.first;
                int weight = it.second;
                if (!visited[v]) 
                {
                    pq.push({weight, v});
                }
            }
        }

        return minCost;
    }
};

int main() 
{
    int n;
    cout << "\nEnter number of vertices: ";
    cin >> n;

    cout << "\nKeep entering edges present in the graph with their weights. Enter -1 for START to STOP.\n";
    Graph g(n);

    g.printGraph();

    int minCost = g.primsAlgo();

    cout << "\nMinimum cost of the spanning tree: " << minCost << endl;

    return 0;
}
