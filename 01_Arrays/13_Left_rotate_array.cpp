// rotate the array to left by d positions..
#include<iostream>
#include<vector>
using namespace std;
 
void rotate_left(vector<int>& array, int &d) {
    for(int i = 0; i < d; i++) {
        int save = array[0];
        for(int j = 0; j < array.size(); j++) {
            if(j+1 < array.size()) {
                array[j] = array[j+1];
            } else {
                array[j] = save;
            }
        }
         for(auto x: array) {
                cout<<x<<" ";
        } cout<<endl;
    }
}

int main() {
 
    vector<int> arr = {3, 4, 5, 6 ,7, 1 ,2 };
    int d = 2;
    rotate_left(arr,d);

    cout<<endl;
    for(auto x: arr) {
        cout<<x<<" ";
    }

return 0;
}