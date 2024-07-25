#include<iostream>
#include<vector>
using namespace std;

vector<int> countZeroOne(int *array, int size) {
    vector<int> count(2);
    int countOne = 0;
    int countZero = 0;

    for(int i=0; i<size;i++) {
        if(array[i] == 0) {     
            countZero++;
        } else if(array[i] == 1) {
            countOne++;
        }
    }

    cout<<"inside:"<<endl;
    count[0] = countZero;
    count[1] = countOne;
    return count;
}

int main() {

    int arr[5] = {0,0,1,0,1};
    vector<int> result = countZeroOne(arr,5);

    cout<<"number of zero and ones are:"<<endl;
    for (size_t i = 0; i < 2; i++)
    {
        cout<<result[i]<<" ";            
    }
    
    
return 0;
}