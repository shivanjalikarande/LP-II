#include <iostream>
#include <climits>

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

        void colorVertex(int vertex, int* color, int maxCnt, int usedClrs, int& minClrs)
        {
            if(usedClrs >= minClrs)
            {
                return;
            }
            if(vertex == n)
            {
                if(usedClrs < minClrs)
                {
                    minClrs = usedClrs;
                }
                return;
            }

            for(int i=0;i<maxCnt;i++)
            {
                if(canColor(vertex,color,i))
                {
                    color[vertex] = i;
                    int newUsedClrs = max(i+1, usedClrs);
                    colorVertex(vertex+1,color,maxCnt,newUsedClrs,minClrs);
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

    cout<<"\nPrinting graph: "<<endl;
    g.printGraph();
    cout<<"\n"<<endl;

    int *color = new int[n];
    for(int i=0;i<n;i++)
    {
        color[i] = -1;
    }

    int cntUsedClrs = 0;
    int minClrs = INT_MAX;

    g.colorVertex(0,color,n,cntUsedClrs,minClrs);

    cout<<"Minimum no of colors required to color graph: "<<minClrs<<endl;



    return 0;
}