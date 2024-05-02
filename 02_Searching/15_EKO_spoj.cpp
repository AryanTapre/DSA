#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<iostream>

using namespace std;
 



bool isCutPossible(vector<int> trees, int m, int sawBladeHeight) {
    long long remainingTreeHeights = 0;

    for(int i=0; i<trees.size(); i++) { // linear search - O(N)
        trees[i] = trees[i] - sawBladeHeight;
        if(trees[i] > 0) {
            remainingTreeHeights += trees[i];
        }
    }

    if(remainingTreeHeights >= m) {
        return true;
    } 
    return false;
}

long long cut_wood(vector<int> &trees, int m) { // O(logZ*N), Z represents searchSpace from 0 to maximum element in trees array
    long long ans = -1;
    long long start = 0;
    long long end = *max_element(trees.begin(), trees.end());
    long long mid;

    while(start <= end) {
        mid = start + (end-start) / 2;

        if(isCutPossible(trees,m,mid)) {
            ans = mid;
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    return ans;

}

int main() {
 
    vector<int> trees = {4, 42, 40, 26 ,46};
    int m = 20;

    cout<<cut_wood(trees,m);

return 0;
}
