#include<iostream>
using namespace std;

void print(int *array, size_t size) {
    if(size == 0) {
        cout<<"array is empty!";
        return;
    }

    for(int i=0; i<size; i++) {
        cout<<array[i]<<" ";
    }
}

int search_element(int *array, size_t size,int key) {
    for(int i=0; i<size; i++) {
        if(array[i] == key) return i;
    }
    return -1;
}

void insert_element(int *array,int &size, int pos, int data) {
    if(size == 0) {
        // if the size of array is Zero, then directly insert at first position.
        array[0] = data;
    } 
    else {
        if(pos > size) return;
        if(pos == 0) {
            for(int i=size-1; i>=0 ;i--) {
                array[i+1] = array[i];
            }
            array[0] = data;
        } 
        else if(pos == size) {
            array[pos] = data;
        } 
        else {
            for(int i=size-1; i>=pos; i--) {
                array[i+1] = array[i];
            }
            array[pos] = data;
        }
    }
    size++;
    
}

void delete_element(int *array,int key,int &size) {
    const int  pos = search_element(array,size,key);
    cout<<"pos:"<<pos<<endl;
    
    if(pos != -1) {
        for(int i=pos; i<size-1; i++) {
            array[i] = array[i+1];
        }
    }
    else {
        cout<<"element does not exist!";
        return;
    }
    size--;
}

int main() {

    int array[20];
    int size = 0;
    const int capacity = sizeof(array)/sizeof(array[0]);

    insert_element(array,size,0,10);
    insert_element(array,size,1,100);
    insert_element(array,size,2,200);
    insert_element(array,size,3,1000);
    print(array,size);

    cout<<endl<<"after deletion:"<<endl;
    delete_element(array,200,size);
    print(array,size);

    delete_element(array,10,size);
    print(array,size);

return 0;
}



