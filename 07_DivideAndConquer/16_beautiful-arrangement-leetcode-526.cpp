// leetcode 526
#include<vector>
#include<iostream>
using namespace std;

void countArrangementHelper(vector<int> &num, int &count, int currentNum ,int &n) {
    if(currentNum > n) {
        ++count;
        return;
    }

    for(int i=1; i<=n; i++) {
        if(num[i] == 0 && (currentNum % i == 0 || i % currentNum == 0)) {
            num[i] = currentNum;
            countArrangementHelper(num, count, currentNum + 1, n);

            // backtracking..
            num[i] = 0;
        }
    }
}

int countArrangement(int n) {
    int count = 0;
    vector<int> num(n+1,0);
    int currentNum = 1;

    countArrangementHelper(num,count,currentNum,n);
    return count;
}

int main() {
    int n = 2;
    cout<<countArrangement(n)<<endl;
return 0;
}