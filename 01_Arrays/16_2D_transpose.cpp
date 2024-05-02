#include<iostream>
using namespace std;
 
int main() {
    
    int arr[][3] = 
    {
        {1,2,3},
        {4,5,6},
        {7,8,9},
        {10,11,12}
    };

    int transpose_array[3][4];
    for(int i=0; i<4; i++) {
        for(int j=0; j<3; j++) {
            transpose_array[j][i] = arr[i][j];
        }    
    }

    cout<<"before:"<<endl;
    for(int i=0; i<4; i++) {
        for(int j=0; j<3; j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;    
    }

    cout<<endl<<"after:"<<endl;

    for(int i=0; i<3; i++) {
        for(int j=0; j<4; j++) {
            cout<<transpose_array[i][j]<<" ";
        }
        cout<<endl;    
    }

return 0;
}