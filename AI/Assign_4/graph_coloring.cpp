#include <iostream>
using namespace std;

class Graph
{
    int n;
    int **graph;

public:
    Graph(int a)
    {
        n = a;
        graph = new int *[n];
        for (int i = 0; i < n; i++)
        {
            graph[i] = new int[n];
            for (int j = 0; j < n; j++)
            {
                graph[i][j] = 0;
            }
        }
    }

    void readGraph()
    {
        cout << "\nEnter adjacency matrix of the graph:\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> graph[i][j];
            }
        }
    }

    void showGraph()
    {
        cout << "\nGraph Matrix:\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << graph[i][j] << " ";
            }
            cout << endl;
        }
    }

    bool canIColor(int v, int clr, int *color)
    {
        for (int i = 0; i < n; i++)
        {
            if (graph[v][i] && color[i] == clr)
            {
                return false;
            }
        }
        return true;
    }

    void colorVertex(int v, int *color, int m)
    {
        if (v == n)
        {
            cout << "Coloring Solution: ";
            for (int i = 0; i < n; i++)
            {
                cout << color[i] << " ";
            }
            cout << endl;
            return;
        }

        for (int clr = 0; clr < m; clr++)
        {
            if (canIColor(v, clr, color))
            {
                color[v] = clr;
                colorVertex(v + 1, color, m);
                color[v] = -1; // Backtrack
            }
        }
    }

    ~Graph()
    {
        for (int i = 0; i < n; i++)
        {
            delete[] graph[i];
        }
        delete[] graph;
    }
};

int main()
{
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    Graph g(n);
    g.readGraph();
    g.showGraph();

    int *color = new int[n];
    for (int i = 0; i < n; i++)
    {
        color[i] = -1;
    }

    int m;
    cout << "\nEnter number of available colors: ";
    cin >> m;

    cout << "\nAll possible colorings with " << m << " colors:\n";
    g.colorVertex(0, color, m);

    delete[] color;
    return 0;
}
