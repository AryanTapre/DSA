// gfg: First Repeating Element

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
int first_repeated(int *arr, int n) {
     unordered_map<int,int> hash;
        int res = -1;
        for(int i=0; i<n;i++) {
            hash[arr[i]]++;   
        }
        
        for(int i=0; i<n;i++) {
            if(hash[arr[i]] > 1) {
                res = i+1;
                break;
            }
        }
        return res;
}

int main() {
 
    int arr[] = {1, 5, 3, 4, 3, 5, 6};
    int n = sizeof(arr)/sizeof(int);

    cout<<first_repeated(arr,n);

return 0;
}