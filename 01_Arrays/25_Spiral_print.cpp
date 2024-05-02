// leetcode 54: Spiral Matrix
#include<vector>
#include<iostream>
using namespace std;
 
vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();
        int total_elements = m*n;

        int starting_row = 0;
        int ending_col = n-1;
        int ending_row = m-1;
        int starting_col = 0;

        int count = 0;

        while(count < total_elements) {

          //starting row
          for(int i=starting_col; i<=ending_col && count<total_elements;i++) {
            ans.push_back(matrix[starting_row][i]);
            count++;
          }
          starting_row++;

          //ending col
          for(int i=starting_row; i<=ending_row && count<total_elements;i++) {
            ans.push_back(matrix[i][ending_col]);
            count++;
          }
          ending_col--;

          //ending row
          for(int i=ending_col; i>=starting_col && count<total_elements;i--) {
            ans.push_back(matrix[ending_row][i]);
            count++;
          }
          ending_row--;
          //starting col
          for(int i=ending_row; i>=starting_row && count<total_elements;i--) {
            ans.push_back(matrix[i][starting_col]);
            count++;
          }
           starting_col++;
        }
        return ans;
}

int main() {
 
    vector<vector<int> > matrix(4,vector<int>(4));
    matrix = 
    {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
 

    vector<int> result = spiralOrder(matrix);

    for(auto x : result) {
        cout<<x<<" ";
    }

return 0;
}