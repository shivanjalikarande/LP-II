#include <iostream>
#include <vector>
using namespace std;
int n;

// N- Queen Problem

void printSol(vector<vector<int>>board)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool isSafe(int row,int col,vector<bool>& rows,vector<bool>& leftDiagonal,vector<bool>&rightDiagonal)
{
    if(rows[row] == true || leftDiagonal[row+col] == true || rightDiagonal[row-col+n-1] == true)
    {
        return false;
    }
    return true;
}

bool solve(vector<vector<int>>&board,int col,vector<bool>&rows,vector<bool>&leftDiagonal,vector<bool>&rightDiagonal)
{
    if(col > n-1)
    {
        return true;
    }
    for(int i=0;i<n;i++)
    {
        if(isSafe(i,col,rows,leftDiagonal,rightDiagonal))
        {
            rows[i] = true;
            leftDiagonal[i+col] = true;
            rightDiagonal[i-col+n-1] = true;
            board[i][col] = 1;

            if(solve(board,col+1,rows,leftDiagonal,rightDiagonal))
            {
                return true;
            }

            rows[i] = false;
            leftDiagonal[i+col] = false;
            rightDiagonal[i-col+n-1] = false;
            board[i][col] = 0;
        }
    }
    return false;
}

int main()
{
    cout<<"Enter size of board: ";
    cin>>n;
    vector<vector<int>>board(n,vector<int>(n,0));

    vector<bool>rows(n,false);
    vector<bool>leftDiagonal(2*n-1,false);
    vector<bool>rightDiagonal(2*n-1,false);

    bool ans = solve(board,0,rows,leftDiagonal,rightDiagonal);

    if(ans)
    {
        cout<<"\nPlaced Queens Solution"<<endl;
        printSol(board);
    }



    return 0;
}