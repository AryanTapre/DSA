#include<iostream>
#include<vector>
using namespace std;

void printBoard(vector<vector<char>> &board, int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}


bool isSafe(int row, int col, vector<vector<char>> &board, int n) {
    // check left..
    int i = row;
    int j = col;
    while(j >= 0) {
        if(board[i][j] == 'Q') return false;
        j--;
    }

    // left upper diagonal
    i = row;
    j = col;
    while(i>=0 && j>=0) {
        if(board[i][j] == 'Q') return false;
        i--;
        j--;
    }

    // left bottom diagonal..
    i = row;
    j = col;
    while(i<n && j>=0) {
        if(board[i][j] == 'Q') return false;
        i++;
        j--;
    }

    return true;
}

void solveQueens(int n, int col, vector<vector<char>> &board) {
    if(col >= n) {
        printBoard(board,n);
        return;
    }

    for(int i=0; i<n; i++) {
        if(isSafe(i,col,board,n)) {
            board[i][col] = 'Q';
            solveQueens(n, col+1, board);
            board[i][col] = '-';
        }
    }
}

int main() {

    int n = 25;
    int col = 0;
    vector<vector<char>> board(n,vector<char>(n,'-'));
    cout<<endl;
    solveQueens(n, col, board);

return 0;
}