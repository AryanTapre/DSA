//TODO: Aggressive Cows gfg practice

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool isPossible(vector<int> &stalls, int k, int distance) {
    int cow = 1;
    int previous_cow_position = 0;
    for(int i = 1; i < stalls.size(); i++) {
        if(stalls[i] - stalls[previous_cow_position] >= distance) {
            cow++;
            previous_cow_position = i;

            if(cow >= distance) {
                return true;
            }
        }
    }
    return false;
}

int solve(vector<int> &stalls, int k) {
    sort(stalls.begin(), stalls.end());

    int start = 0;
    int end = stalls[stalls.size()-1] - stalls[0];
    int mid;
    int ans = -1;

    while(start <= end) {
        mid = start + (end-start) / 2;

        if(isPossible(stalls,k,mid)) {
           ans = mid;
           start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return ans;
}

int main() {
    vector<int> stalls = {1,2,4,9,7};
    int k = 3;

    cout<<solve(stalls,k);

    return 0;
}
 