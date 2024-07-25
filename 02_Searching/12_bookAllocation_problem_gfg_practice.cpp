//TODO: Allocate minimum number of pages


#include<iostream>
#include<numeric>
using namespace std;
 
bool isValidAssignment(int A[],int sol, int N, int M) {
    	int sum_page = 0;
    	int count = 1;
    	for(int i =0; i < N; i++) { 
    		if(A[i] > sol) return false;
    		if(sum_page+A[i] > sol) { 
    			count++;
    			sum_page = A[i];
    			if(count > M) {
    				return false;
    		    }
    		}
    		else {
    			sum_page+= A[i];
    		}
    	}
    	return true;
}   
   
int findPages(int A[], int N, int M) 
{
        int ans = -1;
        if(M > N) return ans;
        
        
    	int start = 0;
    	int end = accumulate(A,A+N,0);
    	int mid;
    	while(start <= end){
    		mid = start + (end-start)/2;
    		if(isValidAssignment(A,mid,N,M)) {
    			ans = mid;
    		
    			end = mid - 1;
    		} else {
    				start = mid + 1;
    		}
    	}
    	return ans;
}

int main() {
	int A[] = {16,45,67,90};
	int m = 2;
	int n = 4;

	cout<<findPages(A,n,m);

return 0;
}