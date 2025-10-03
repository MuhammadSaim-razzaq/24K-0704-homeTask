#include <iostream>
using namespace std;

int totalSolutions = 0;

void printBoard(int board[20][20], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 1)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(int board[20][20], int row, int col, int n) {
    for (int i = 0; i < row; i++)
        if (board[i][col] == 1)
            return false;

    for (int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return false;

    for (int i = row-1, j = col+1; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 1)
            return false;

    return true;
}

bool solveNQueens(int board[20][20], int row, int n, bool printOne) {
    if (row == n) {
        totalSolutions++;
        if (printOne && totalSolutions == 1)
            printBoard(board, n);
        return true;
    }

    bool found = false;
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 1;
            if (solveNQueens(board, row+1, n, printOne))
                found = true;
            board[row][col] = 0;
        }
    }
    return found;
}

int main() {
    int n;
    cout << "Enter the value of N: ";
    cin >> n;

    int board[20][20] = {0};

    cout << "\nOne valid board configuration:\n";
    solveNQueens(board, 0, n, true);

    totalSolutions = 0;
    solveNQueens(board, 0, n, false);
    cout << "Total number of distinct solutions for N = " << n << " is: " << totalSolutions << endl;

    return 0;
}
