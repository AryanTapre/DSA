#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;


unordered_map<int, bool> checkRow;
unordered_map<int, bool> checkUpperLeftDiagonal;
unordered_map<int, bool> checkBottomLeftDiagonal;


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
    if(checkRow[row] == false) {
        if(checkUpperLeftDiagonal[(row-col)+n] == false) {
            if(checkBottomLeftDiagonal[row+col] == false) {
                return true;
            }
        }
    }
    return false;


    // // check left..
    // int i = row;
    // int j = col;
    // while(j >= 0) {
    //     if(board[i][j] == 'Q') return false;
    //     j--;
    // }

    // // left upper diagonal
    // i = row;
    // j = col;
    // while(i>=0 && j>=0) {
    //     if(board[i][j] == 'Q') return false;
    //     i--;
    //     j--;
    // }

    // // left bottom diagonal..
    // i = row;
    // j = col;
    // while(i<n && j>=0) {
    //     if(board[i][j] == 'Q') return false;
    //     i++;
    //     j--;
    // }

    // return true;
}

void solveQueens(int n, int col, vector<vector<char>> &board) {
    if(col >= n) {
        printBoard(board,n);
        return;
    }

    for(int i=0; i<n; i++) {
        if(isSafe(i,col,board,n)) {
            board[i][col] = 'Q';
            checkRow[i] = true;
            checkUpperLeftDiagonal[(i-col)+n] = true;
            checkBottomLeftDiagonal[i+col] = true;


            solveQueens(n, col+1, board);

            board[i][col] = '-';
            checkRow[i] = false;
            checkUpperLeftDiagonal[(i-col)+n] = false;
            checkBottomLeftDiagonal[i+col] = false;    
            
        }
    }
}

int main() {

    int n = 2   0;
    int col = 0;
    vector<vector<char>> board(n,vector<char>(n,'-'));
    cout<<endl;
    solveQueens(n, col, board);

return 0;
}