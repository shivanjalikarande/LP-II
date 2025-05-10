#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Graph
{
    unordered_map<int, vector<int>> adjMatrix;

public:
    void scanGraph()
    {
        cout << "\nEnter vertices starting from 1 to n" << endl;
        cout << "\nEnter edges of graph. Enter -1 as Start to STOP" << endl;
        int start, end;
        while (1)
        {
            cout << "\nStart vertex: ";
            cin >> start;
            if (start == -1)
            {
                break;
            }
            cout << "End vertex: ";
            cin >> end;
            if (end == -1)
            {
                break;
            }

            adjMatrix[start].push_back(end);
            adjMatrix[end].push_back(start);
        }
    }

    void printGraph()
    {
        cout << "\nPrinting adjMatrix" << endl;
        for (auto row : adjMatrix)
        {
            cout << row.first << " -> ";
            for (int x : row.second)
            {
                cout << x << " ";
            }
            cout << endl;
        }
    }

    void DFS()
    {
        vector<int> visited(adjMatrix.size() + 1, 0);
        int source;
        int level = 0;
        cout << "\nEnter source vertex for DFS Traversal: ";
        cin >> source;
        DFS_Rec(source, visited, level);
    }

    void DFS_Rec(int src, vector<int> &visited, int level)
    {
        cout << src << " at level : " << level << endl;
        visited[src] = 1;

        for (int neighbour : adjMatrix[src])
        {
            if (!visited[neighbour])
            {
                DFS_Rec(neighbour, visited, level + 1);
            }
        }
    }

    void BFS()
    {
        vector<int> visited(adjMatrix.size() + 1, 0);
        vector<int> level(adjMatrix.size() + 1, -1);
        int source;
        cout << "\nEnter source vertex for BFS Traversal: ";
        cin >> source;
        BFS_helper(source, visited, level);
    }

    void BFS_helper(int src, vector<int> &visited, vector<int> &level)
    {
        queue<int> qu;
        qu.push(src);
        visited[src] = 1;
        level[src] = 0;

        while (!qu.empty())
        {
            src = qu.front();
            qu.pop();
            cout << src << " at level : " << level[src] << endl;
            for (int neighbour : adjMatrix[src])
            {
                level[neighbour] = level[src] + 1;
                if (!visited[neighbour])
                {
                    qu.push(neighbour);
                    visited[neighbour] = 1;
                }
            }
        }
    }
};

int main()
{
    Graph g;

    char cntinue = 'n';
    do
    {
        cout << "\nEnter operation to perform:\n1.Scan Graph\n2.Print Graph\n3.DFS Traversal\n4.BFS Traversal" << endl;
        int option;
        cin >> option;
        switch (option)
        {
            case 1:
                g.scanGraph();
                break;
            case 2:
                g.printGraph();
                break;
            case 3:
                g.DFS();
                break;
            case 4:
                g.BFS();
                break;
            default:
                cout << "\nPlease enter correct option" << endl;
                break;
        }
        cout<<"\nWant to continue? (y/n): ";
        cin>>cntinue;
    }while(cntinue == 'y');

    return 0;
}