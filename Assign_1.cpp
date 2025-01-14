#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;


/*Implement depth first search algorithm and Breadth First Search algorithm, use an undirected
graph and develop a recursive algorithm for searching all the vertices of a graph or tree data
structure.*/


class Graph
{
    unordered_map<int, vector<int>> adjMatrix;

public:
    Graph()
    {
        
    }

    void scanGraph()
    {
        cout << "\nKeep entering edges. Enter '-1' as START to stop scanning" << endl;
        int start, end;
        while (1)
        {
            cout << "\nEnter start vertex: ";
            cin >> start;
            if(start == -1)
            {
                break;
            }
            cout << "\nEnter end vertex: ";
            cin >> end;
            adjMatrix[start].push_back(end);
            adjMatrix[end].push_back(start);
        }
        cout << "\nAll vertices are scanned successfully" << endl;
    }

    void printGraph()
    {
        cout << "\n------------ Graph ------------" << endl;
        for(const auto& pair:adjMatrix)
        {
            cout << pair.first << ": ";
            for(auto vertex: pair.second)
            {
                cout << vertex << " ";
            }
            cout << endl;
        }
    }

    void DFS(int vertex)
    {
        vector<int> visited(adjMatrix.size()+1, 0);
        DFS_Rec(vertex, visited);
    }

    void DFS_Rec(int vertex,vector<int>& visited)
    {
        cout << vertex << " ";
        visited[vertex] = 1;

        for(int neighbor : adjMatrix[vertex])
        {
            if(visited[neighbor] == 0)
            {
                DFS_Rec(neighbor, visited);
            }
        }

    }

    void BFS_helper(int vertex)
    {
        vector<int> visited(adjMatrix.size()+1, 0);
        BFS(vertex, visited);
    }

    void BFS(int vertex,vector<int>& visited)
    {
        queue<int> que;
        visited[vertex] = 1;
        que.push(vertex);

        while(!que.empty())
        {
            int current = que.front();
            cout << current << " ";
            que.pop();
            for(int neighbor:adjMatrix[current])
            {
                if(visited[neighbor] == 0)
                {
                    que.push(neighbor);
                    visited[neighbor] = 1;
                }
            }
        }
    }
};

int main()
{
    Graph g;
    g.scanGraph();
    g.printGraph();

    int start;
    cout << "\nEnter start vertex: ";
    cin >> start;


    cout << "\nDFS Recursive : ";
    g.DFS(start);

    cout << "\nBFS Recursive: ";
    g.BFS_helper(start);

    return 0;
}