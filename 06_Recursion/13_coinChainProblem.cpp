// solve coin change problem..

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int minCoin(vector<int> &a, int target) {
    if(target == 0) return 0; // base case

    int mini = INT_MAX;
    for(int i : a) {
        if(target - i >= 0) { // skiping negative calls..
            int ways = minCoin(a, target - i) + 1;
            mini = min(ways, mini);
        }
    }
    return mini;
}

int main() {
    vector<int> a = {2,1};
    cout<<minCoin(a,5)<<endl;
return 0;
}