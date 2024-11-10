//TODO: leetcode 532 K-diff pair in Array

#include<algorithm>
#include<set>
#include<vector>
#include<iostream>
using namespace std;

int binary_search(vector<int> &nums, int start, int k) {
    int end = nums.size()-1;
    int mid;

    while(start <= end) {
        mid = start + (end-start)/2;
        if(nums[mid] == k) {
            return mid;   
        }
        else if(k > nums[mid]) {
            start = mid+1;
        }
        else {
            end = mid-1;
        }
    }
    return -1;
}

int find_pairs(vector<int> &nums, int k) {
    //FIXME: using binary search Appraoch
    set<pair<int, int> > ans;
    for(int i=0; i<nums.size(); i++) {
        if(binary_search(nums, i+1, nums[i]+k) != -1) {
            ans.insert(make_pair(nums[i],nums[i]+k));
        }
    }
    return ans.size();


    //FIXME: two pointer approach
    // sort(nums.begin(), nums.end());
    // set<pair<int,int> > ans;
    // int i=0,j=1;

    // while(j < nums.size()) {
    //     int diff = nums[j] - nums[i];
    //     if(diff == k) {
    //         ans.insert(make_pair(nums[i],nums[j]));
    //         ++i,++j;
    //     }
    //     else if(diff < k) {
    //         j++;
    //     }
    //     else {
    //         i++;
    //     }

    //     if(i == j) j++;
    // }

    // return ans.size();

}


int main() {
 
return 0;
}