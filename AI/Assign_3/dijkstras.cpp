#include <iostream>
#include <climits>
using namespace std;


class Graph
{
    int n;
    int **graph;
    public:
        Graph()
        {
            cout<<"\nEnter no of vertices in graph: ";
            cin>>n;
            graph = new int*[n];
            for(int i=0;i<n;i++)
            {
                graph[i] = new int[n];
            }
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    graph[i][j] = INT_MAX;
                }
            }
        }

        void scanGraph()
        {
            cout<<"\nKeep entering edges with weights. Enter -1 to STOP"<<endl;
            int u,v,wt;
            while(1)
            {
                cout<<"\nEnter start vertex: ";
                cin>>u;
                if(u == -1) break;
                cout<<"Enter end vertex: ";
                cin>>v;
                if(v == -1) break;
                cout<<"Enter weight: ";
                cin>>wt;
                graph[u][v] = wt;
                graph[v][u] = wt;
            }
        }

        void printGraph()
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(graph[i][j] == INT_MAX)
                    {
                        cout<<0<<" ";
                    }
                    else
                    {
                        cout<<graph[i][j]<<" ";
                    }
                }
                cout<<endl;
            }
        }

        void DijkstrasAlgo()
        {
            int *visited = new int[n];
            int *distance = new int[n];
            int *from = new int[n];

            int source;
            cout<<"\nEnter source vertex: ";
            cin>>source;

            for(int i=0;i<n;i++)
            {
                visited[i] = 0;
                distance[i] = graph[source][i];
                from[i] = source;
            }

            distance[source] = 0;
            visited[source] = 1;
            
            int ne = n-1;
            int v = source;

            while(ne > 0)
            {
                int min = INT_MAX;
                for(int i=0;i<n;i++)
                {
                    if(!visited[i] && distance[i] < min)
                    {
                        min = distance[i];
                        v = i;
                    }
                }

                visited[v] = 1;

                for(int i=0;i<n;i++)
                {
                    if(!visited[i] && graph[v][i] != INT_MAX && (distance[i] > (graph[v][i] + distance[v])))
                    {
                        distance[i] = graph[v][i] + distance[v];
                        from[i] = v;
                    }
                }
                ne--;
            }

            int temp = n-1;
            while(temp != source)
            {
                cout<<temp<<" visited"<<endl;
                temp = from[temp];
            }
            cout<<temp<<" is visited"<<endl;
            cout<<"\nMinimum Cost : "<<distance[n-1];
        }

};

int main()
{
    Graph g;
    g.scanGraph();
    g.printGraph();

    cout<<"Minimum cost path: "<<endl;
    g.DijkstrasAlgo();

    return 0;
}