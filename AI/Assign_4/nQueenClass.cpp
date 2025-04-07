#include <iostream>
#include <vector>
using namespace std;

// N-Queen Problem 
class nQueen {
    int N;
    vector<vector<int>> board;
    vector<bool> rows, leftDiagonal, rightDiagonal;

public:
    nQueen() {
        cout << "Enter size of board: ";
        cin >> N;

        board.resize(N, vector<int>(N, 0));
        rows.resize(N, false);
        leftDiagonal.resize(2 * N - 1, false);
        rightDiagonal.resize(2 * N - 1, false);
    }

    // Function to print the board
    void printSol() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Function to check if a queen can be placed at board[row][col]
    bool isSafe(int row, int col) {
        return !rows[row] && !leftDiagonal[row + col] && !rightDiagonal[row - col + N - 1];
    }

    // Recursive function 
    bool solve(int col) {
        if (col == N) return true; // Base case: All queens placed

        for (int i = 0; i < N; i++) {
            if (isSafe(i, col)) {
                // Place queen
                rows[i] = leftDiagonal[i + col] = rightDiagonal[i - col + N - 1] = true;
                board[i][col] = 1;

                // Recursive call
                if (solve(col + 1)) return true;

                // Backtrack
                rows[i] = leftDiagonal[i + col] = rightDiagonal[i - col + N - 1] = false;
                board[i][col] = 0;
            }
        }
        return false;
    }

   
    void solveNQueens() {
        if (solve(0)) {
            cout << "\nPlaced Queens Solution:\n";
            printSol();
        } else {
            cout << "\nNo solution exists.\n";
        }
    }
};


int main() {
    nQueen q;
    q.solveNQueens();
    return 0;
}
