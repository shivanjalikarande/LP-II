#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

#define N 3


class Tiles
{
    public:
        int tiles[N][N];
        int x,y,nx,ny,g,h;
        Tiles* parent;

        Tiles(Tiles* parent,int matrix[N][N],int x, int y, int nx, int ny, int g)
        {
            for(int i=0;i<N;i++)
            {
                for(int j=0;j<N;j++)
                {
                    tiles[i][j] = matrix[i][j];
                }
            }

            h = INT_MAX;
            this->g = g;
            swap(tiles[x][y],tiles[nx][ny]);
            this->x = nx;
            this->y = ny;
            this->parent = parent;
        }
};

void printMatrix(int mat[N][N],int g,int h)
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"\ng= "<<g<<"\nh= "<<h<<"\nf= "<<(g + h);
}

void printPath(Tiles* T)
{
    if(T == NULL)
    {
        return;
    }
    printPath(T->parent);
    printMatrix(T->tiles,T->g,T->h);
}

int heuristic(int currTiles[N][N], int goal[N][N])
{
    int cnt = 0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(currTiles[i][j] && currTiles[i][j] != goal[i][j])
            {
                cnt++;
            }
        }
    }
    return cnt;
}

struct comp
{   
    bool operator()(Tiles* lhs, Tiles* rhs)const
    {
        return (lhs->g + lhs->h) > (rhs->g + rhs->h);
    }
};

void solve(int start[N][N], int goal[N][N], int x, int y)
{
    Tiles* tileObj = new Tiles(NULL,start,x,y,x,y,0);
    tileObj->h = heuristic(tileObj->tiles,goal);

    priority_queue<Tiles*,vector<Tiles*>,comp>pq;

    pq.push(tileObj);

    while(!pq.empty())
    {
        Tiles *currState = pq.top();
        if(currState -> h == 0)
        {
            printPath(currState);
            return;
        }

        pq.pop();

        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};

        for(int i=0;i<4;i++)
        {
            int nx = currState->x + dx[i];
            int ny = currState->y + dy[i];
            if(nx >= 0 && ny >= 0 && nx < N && ny < N)
            {
                Tiles* newState = new Tiles(currState,currState->tiles,currState->x,currState->y,nx,ny,currState->g+1);
                newState->h = heuristic(newState->tiles,goal);
                pq.push(newState);
            }
        }
    }

}

int main()
{
    int start[N][N];
    int goal[N][N];

    //x,y = coordinates of blank tile
    int x = -1;
    int y = -1;

    cout<<"Enter '0' for blank tile"<<endl;

    cout<<"\nEnter start state: ";
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>start[i][j];
            if(start[i][j] == 0)
            {
                x = i;
                y = j;
            }
        }
    }

    cout<<"\nEnter goal state: ";
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>goal[i][j];
        }
    }

    solve(start,goal,x,y);


    return 0;
}