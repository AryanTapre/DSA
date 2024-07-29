// Leetcode : 279

#include<iostream>
#include<math.h>
#include<climits>
using namespace std;

int helper(int n) {
    if(n == 0) return 1;
    if(n < 0) return 0;

    int ans = INT_MAX;
    int i = 1;
    int end = sqrt(n);

    while(i <= end) {
        int perfectSquare = i * i;
        int noOfSquares = helper(n - perfectSquare) + 1;

        if(noOfSquares < ans) ans = noOfSquares;

        i++;
    }
    return ans;
}

int numSquares(int n) {
    return helper(n) - 1;
    
}

int main() {
    cout<<numSquares(13)<<endl;
return 0;
}