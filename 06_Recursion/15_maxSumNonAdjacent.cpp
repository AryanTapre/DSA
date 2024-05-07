// return maximum sum of non-adjacent elements in an Array..

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

void maxSumNonAdjacent(vector<int> &data, int i, int &maxi, int sum) {
    if(i >= data.size()) {
        maxi = max(sum, maxi);
        return;
    }
    maxSumNonAdjacent(data, i+2, maxi, sum + data[i]); // include 
    maxSumNonAdjacent(data, i+1, maxi, sum); // exclude
}

int main() {

    vector<int> data = {2,1,4,9};
    int i = 0;
    int maxi = INT_MIN;
    int sum = 0;

    maxSumNonAdjacent(data, i, maxi, sum);
    cout<<maxi<<endl;
return 0;
}