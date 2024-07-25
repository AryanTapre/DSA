#include<vector>
#include<limits.h>
#include<iostream>
using namespace std;
 
vector<int> intersection_array(vector<int>& A, vector<int>& B) {
    vector<int> result;

    for(int i = 0; i < A.size(); i++) {
        for(int j = 0; j < B.size(); j++) {
            if(A[i] == B[j]) {
                result.push_back(A[i]);
                B[j] = INT_MIN;
            }        
        }
    }
    return result;   
}

int main() {
 
    vector<int> A {3,1,8,16,32,10};
    vector<int> B {32,8,10,12,13,14};

    
    vector<int> result = intersection_array(A,B);
    for(auto x: result) {
        cout<<x<<" ";
    }

return 0;
}