#include<iostream>
using namespace std;
 
void extreme_print(int *array, int size) {
    int front = 0;
    int rear = size-1;

    while(front < rear) {
        cout<<array[front]<<" "<<array[rear]<<" ";
        front++;
        rear--;
    }
    if(front == rear) {
        cout<<array[front];
    }
}

int main() {

 int array[] = {12,5,6,8,0,4,5};
 int size = sizeof(array)/sizeof(array[0]);
 
 extreme_print(array,size);

return 0;
}