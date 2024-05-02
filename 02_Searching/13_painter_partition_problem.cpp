// gfg practice: painters partition problem
#include<iostream>
using namespace std;

bool isPossible(int arr[], int n, int k, int solution) {
        long long boardSum = 0;
        long long  painterCount = 1;
        
        for(int i=0; i<n; i++) {
            if(arr[i] > solution) {
                return false;
            }
            
            if(boardSum + arr[i] > solution) {
                painterCount++;
                boardSum = arr[i];
                if(painterCount > k) {
                    return false;
                }
            }
            else {
                boardSum += arr[i];
            }
        }
        return true;
    }

long long minTime(int arr[], int n, int k)
    {
        
        long long start = 0;
        long long end = 0;
        
        for(int i=0; i<n; i++) {
            end+= arr[i];
        }
        
        long long ans = -1;
        long long mid = 0;
        
        
        while(start <= end) {
            mid = start + (end-start) / 2;
            
            if(isPossible(arr,n,k,mid)) {
                ans = mid;
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        
        return ans;    
    }

int main() {
 
return 0;
}