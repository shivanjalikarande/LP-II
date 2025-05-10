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
            graph = new int*[n];
            for(int i=0;i<n;i++)
            {
                graph[i] = new int[n];
            }
        }
        void scanGraph()
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    cin>>graph[i][j];
                }
            }
        }

        void printGraph()
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    cout<<graph[i][j]<<" ";
                }
                cout<<endl;
            }
        }

        bool canColor(int vertex, int* color, int clr)
        {
            for(int i=0;i<n;i++)
            {
                if(graph[vertex][i] && color[i] == clr)
                {
                    return false;
                }
            }
            return true;
        }

        void colorVertex(int vertex, int* color, int clrCnt, bool &found)
        {
            if(vertex == n)
            {
                found = true;
                for(int i=0;i<n;i++)
                {
                    cout<<color[i]<<" ";
                }
                cout<<endl;
                return;
            }

            for(int i=0;i<clrCnt;i++)
            {
                if(canColor(vertex,color,i))
                {
                    color[vertex] = i;
                    colorVertex(vertex+1,color,clrCnt,found);
                    color[vertex] = -1;
                }
            }
        }
};


int main()
{
    int n;
    cout<<"Enter no of vertices: ";
    cin>>n;
    Graph g(n);

    g.scanGraph();
    g.printGraph();

    int *color = new int[n];
    for(int i=0;i<n;i++)
    {
        color[i] = -1;
    }

    int m;
    cout<<"\nEnter no of colors: ";
    cin>>m;

    bool found = false;
    g.colorVertex(0,color,m,found);

    if(!found)
    {
        cout<<"\nNo any possible combination exists for "<<m<<" colors"<<endl;
    }

    return 0;
}