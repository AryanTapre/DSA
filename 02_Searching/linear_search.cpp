// TODO: Approaching Linear Searching...

#include<iostream>
using namespace std;
 
int linear_search(int* array, int n, int k) { // O(N);
    int operation_count = 1;
    for(int i = 0; i < n; i++) {
        cout<<"operation:"<<operation_count++<<endl;
        if(array[i] == k) {
            return i;
        }
    }
    return -1;
}

int main() {
 
    int array[] = {1,2,3,4,5,6,7,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50};
    int n = 50;

    cout<<"result :"<<linear_search(array,n,31);

return 0;
}