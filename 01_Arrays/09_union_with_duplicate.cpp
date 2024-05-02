#include<limits.h>
#include<vector>
#include<iostream>
using namespace std;
 
vector<int> Union(vector<int> A, vector<int> B) {
    vector<int> result;
    for(int i = 0; i < A.size(); i++) {
        for(int j = 0; j < B.size(); j++) {
            if(A[i] == B[j]) {
                B[j] = INT_MIN;
            }
        }
    }

    for(int i = 0; i < A.size(); i++) {
        if(A[i] != INT_MIN) {
            result.push_back(A[i]);
        }
    }
    for(int i = 0; i < B.size(); i++) {
        if(B[i] != INT_MIN) {
            result.push_back(B[i]);
        }
    }
    return result;
}

int main() {
 
    vector<int> A {3,1,8,16,32,10};
    vector<int> B {32,8,10,12,13,14};

    Union(A,B);
    vector<int> result = Union(A,B);
    for(auto x: result) {
        cout<<x<<" ";
    }

return 0;
}