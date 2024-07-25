#include<iostream>
using namespace std;
 
void reverse(int *arr, int size) {
    int front = 0;
    int rear = size-1; // Two pointer Approach!.
    while(front < rear) {
        // const int temp = arr[front];
        // arr[front] = arr[rear];
        // arr[rear] = temp;
        swap(arr[front],arr[rear]);

        front++;
        rear--;
    }
}

int main() {
 
    int arr[] = {1,2,3,4,5,9};
    int size = 6;
    reverse(arr,size);

    for(int i=0; i<size; i++) {
        cout<<arr[i]<<" ";
    }

return 0;
}