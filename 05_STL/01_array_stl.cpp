#include<array>
#include<iostream>
using namespace std;
 
int main() {
 
    array<int,6> arr = {1,2,90,67,5,34};
    
    cout<<"size:"<<arr.size();
    cout<<endl<<"max_size():"<<arr.max_size()<<endl;
    int mini = INT_MAX;

    cout<<"first element data:"<<arr.front()<<endl;
    cout<<"last element data:"<<arr.back()<<endl;

   if(arr.empty()) {
    cout<<"array is empty"<<endl;
   } else {
    cout<<"array is not empty"<<endl;
   }

   cout<<"element at index 2:"<<arr.at(2)<<endl;
    

   cout<<"swapping arr[0] and arr[1]"<<endl;
   swap(arr.at(0),arr.at(1));

    for(auto x: arr){
        cout<<x<<" ";
    }

return 0;
}