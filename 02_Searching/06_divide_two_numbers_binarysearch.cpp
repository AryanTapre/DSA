//TODO: Divide 2 numbers using Binary search...

#include<iostream>
using namespace std;
 
int divide(int dividend, int divisor) {
  
    int start = 0;
    int end = abs(dividend);
    int mid;
    int save;

    while(start <= end) {
        mid = start + (end-start) / 2;
        
        if(abs(mid*divisor) == abs(dividend)) {
            save = mid;
            break;
        }
        else if(abs(mid*divisor) < abs(dividend)) {
            save = mid;
            start = mid + 1;
        }
        else {
            //mid*divisor > dividend => left search 
            end = mid - 1;
        }
    }

    if((dividend>0 && divisor >0) || (dividend<0 && divisor<0)) {
        return save;
    }
    else {
        return save * -1;
    }
    
}

int main() {
 
    int dividend = 500;
    int divisor = 2;

    cout<<divide(dividend,divisor)<<endl;

return 0;
}