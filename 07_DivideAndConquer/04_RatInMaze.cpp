#include<vector>
#include<iostream>
using namespace std;

bool isSafe(int x, int y, int row, int col, vector<vector<int> > &maze, vector<vector<bool> > &visited) {
    if(((x>=0 && x<row) && (y>=0 && y<col)) && (maze[x][y] == 1) && (visited[x][y] == false)) {
        return true;
    }
    return false;
}

void solveMaze(vector<vector<int> > &maze, vector<vector<bool> > &visited, int row, int col, int x, int y, vector<string>& path, string output) {
    if(x == row-1 && y == col-1) {
        path.push_back(output);
        return;
    }

    // dir left: i,j-1
    if(isSafe(x, y-1, row, col, maze, visited)) {
        visited[x][y-1] = true;
        solveMaze(maze, visited, row, col, x, y-1, path, output+'L');
        visited[x][y-1] = false;
    }

    // dir right: i,j+1
    if(isSafe(x, y+1, row, col, maze, visited)) {
        visited[x][y+1] = true;
        solveMaze(maze, visited, row, col, x, y+1, path, output+'R');
        visited[x][y+1] = false;
    }

    // dir up: i-1,j
    if(isSafe(x-1, y, row, col, maze, visited)) {
        visited[x-1][y] = true;
        solveMaze(maze, visited, row, col, x-1, y, path, output+'U');
        visited[x-1][y] = false;
    }

    // dir down: i+1,j
    if(isSafe(x+1, y, row, col, maze, visited)) {
        visited[x+1][y] = true;
        solveMaze(maze, visited, row, col, x+1, y, path, output+'D');
        visited[x+1][y] = false;
    }
}

int main() {
    int row = 3;
    int col = 3;

    vector<vector<int> > maze = {
        {1,1,1},
        {1,1,1},
        {0,0,1}
    };

    vector<vector<bool> > visited(row, vector<bool>(col, false));
    visited[0][0] = true;

    vector<string> path;
    string output = "";

    solveMaze(maze, visited, row, col, 0, 0, path, output);

    for(auto i: path) {
        cout<<i<<" ";
    }
    cout<<endl;

return 0;
}