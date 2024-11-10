// leetcode : 1155

#include<iostream>
using namespace std;

int numsRollsToTarget(int n, int k, int target) {
    if(target < 0) return 0;
    if(n == 0 && target == 0) return 1;
    if(n == 0 && target != 0) return 0;
    if(n != 0 && target == 0) return 0;

    int ans = 0;
    for(int i=1; i<=k; i++) {
        ans = ans + numsRollsToTarget(n - 1, k, target - i);
    }
    return ans;
}


int main() {
    int n = 30;
    int k = 30;
    int target = 500;

    cout<<"number of ways to get target is : "<<numsRollsToTarget(n, k, target)<<endl;
return 0;
}
