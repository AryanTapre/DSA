// find Square Root of number using binary search..
#include<iostream>
using namespace std;

double sqrt(int n, int precision) {
    int start = 0;
    int end = n;
    int mid;
    int ans = -1;

    while(start <= end) {
        mid = start + (end - start) / 2;

        if(mid*mid == n) {
            ans = mid;
            break;
        }
        else if(mid*mid < n) {
            ans = mid;
            start = mid + 1;
        }
        else {
            // mid*mid > n
            end = mid - 1;
        }
    }

    // logic for percision
    double step = 0.1;
    double final_ans;

    for(int i = 0; i < precision; i++) {
        for(double j = ans; j*j < n; j = j + step) {
            final_ans = j;
        }
        step/= 10;
    }
    return final_ans;   
}

int main() {
 
    cout<<sqrt(10,3);

return 0;
}