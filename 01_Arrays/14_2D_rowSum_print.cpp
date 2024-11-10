#include<iostream>
using namespace std;

void print_row_sum(int arr[][3], int row, int col) {
    int sum;
    for(int i = 0; i < row; i++) {
        sum = 0;
        for(int j = 0; j < col; j++) {
            sum = sum + arr[i][j];
        }
        cout<<sum<<" ";
    }
}

int main() {
 
    int arr[][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    print_row_sum(arr,3,3);

    cout<<endl<<endl;
    // col * i + j
    cout<<*arr[3 * 2 + 2]<<endl;

return 0;
}