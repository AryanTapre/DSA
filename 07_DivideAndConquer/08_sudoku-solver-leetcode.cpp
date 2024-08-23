// leetcode 37
#include<iostream>
#include<vector>    
using namespace std;

    bool isSafe(vector<vector<char> > &board, int &n, int row, int col, int value) {
        // complete row
        // complete column
        // 3*3 board
        char charValue = value + '0';
        for(int i=0; i<n; i++) {
            if(i == col) { // skip self checking....
                continue;
            }

            if(board[row][i] == charValue) {
                return false;
            }
        }

        for(int i=0; i<n; i++) {
            if(i == row) { // skip self checking....
                continue;
            }

            if(board[i][col] == charValue) {
                return false;
            }
        }

        for(int i=0;i<n;i++) {
            if(board[3*(row/3)+i/3][3*(col/3)+i%3] == charValue) return false;
        }
        return true;

    }

    bool solveSudoku(vector<vector<char> > &board, int &n) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j] == '.') {
                    for(int value=1; value<=9; value++) {
                        if(isSafe(board, n, i, j, value)) {
                            board[i][j] = value + '0';

                            bool ans = solveSudoku(board, n);
                            if(ans == true) {
                                return true;
                            }
                            else {
                                // backtracking...
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            } 
        }
        
        return true;
    }

int main() {

    int n = 9;
    vector<vector<char> > board;
    board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    bool ans = solveSudoku(board, n);

    if(ans == true) {
        for(auto i : board) {
            for(auto j : i) {
                cout<<j<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }else {
        cout<<"enable to solve puzzle.."<<endl;
    }

return 0;
}