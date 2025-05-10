#include <iostream>
#include <queue>
#include <climits>

using namespace std;

#define N 3

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

class Puzzle
{
    public:
        int mat[N][N];      //current state
        int x,y,nx,ny,g,h;  //position of blank tile
        Puzzle* parent;     //previous state

        Puzzle(int init[N][N], int x, int y,int nx, int ny, int g, Puzzle* parent)
        {
            for(int i=0;i<N;i++)
            {
                for(int j=0;j<N;j++)
                {
                    mat[i][j] = init[i][j];
                }
            }

            swap(mat[x][y],mat[nx][ny]);
            this->x = nx;
            this->y = ny;
            this->g = g;
            h = INT_MAX;
            this->parent = parent;
        }

        int calculateHeuristic(int goal[N][N])
        {
            int count = 0;
            for(int i=0;i<N;i++)
            {
                for(int j=0;j<N;j++)
                {
                    if(mat[i][j] != 0 && mat[i][j] != goal[i][j])
                    {
                        count++;
                    }
                }
            }
            return count;
        }

        bool isSame(int goal[N][N])
        {
            for(int i=0;i<N;i++)
            {
                for(int j=0;j<N;j++)
                {
                    if(mat[i][j] != goal[i][j])
                    {
                        return false;
                    }
                }
            }
            return true;
        }

        void printMatrix()
        {
            cout<<endl;
            for(int i=0;i<N;i++)
            {
                for(int j=0;j<N;j++)
                {
                    cout<<mat[i][j]<<' ';
                }
                cout<<endl;
            }
            cout<<"\ng="<<g<<"\nh="<<h<<"\nf="<<(g+h)<<endl;
        }

};

class compareCost
{
    public:
        bool operator()(Puzzle* a, Puzzle* b)
        {
            return (a->g + a->h) > (b->g + b->h);
        }
};

void solve(int start[N][N], int goal[N][N], int x, int y)
{
    priority_queue<Puzzle*,vector<Puzzle*>,compareCost>pq;

    Puzzle *root = new Puzzle(start,x,y,x,y,0,nullptr);
    root->h = root->calculateHeuristic(goal);
    pq.push(root);

    while(!pq.empty())
    {
        Puzzle* curr = pq.top();
        pq.pop();

        if(curr->isSame(goal))
        {
            cout<<"\nSolved in "<<curr->g<<" moves"<<endl;
            cout<<"Steps: \n"<<endl;
            while(curr)
            {
                curr->printMatrix();
                curr = curr->parent;
            }
            return;
        }

        for(int i=0;i<4;i++)
        {
            int nx = curr->x + dx[i];
            int ny = curr->y + dy[i];

            if(nx >= 0 && ny >= 0 && nx < N && ny < N)
            {
                Puzzle* newState = new Puzzle(curr->mat,curr->x,curr->y,nx,ny,curr->g+1,curr);
                newState->h = newState->calculateHeuristic(goal);
                pq.push(newState);
            }
        }
    }
}

int main()
{
    int start[N][N], goal[N][N];
    int blankX, blankY;

    cout<<"\nEnter start state: "<<endl;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>start[i][j];
            if(start[i][j] == 0)
            {
                blankX = i;
                blankY = j;
            }
        }
    }

    cout<<"\nEnter goal state: "<<endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> goal[i][j];
        }
    }

    solve(start,goal,blankX,blankY);

    return 0;
}