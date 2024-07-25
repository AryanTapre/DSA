// GFG: Add two numbers represented by two arrays
#include<iostream>
#include<algorithm>
using namespace std;

string calc_Sum(int *a,int n,int *b,int m){
        string ans;
        int i = n-1;
        int j = m-1;
        int carry = 0;
        
        while(i>=0 && j>=0) {
            int x = a[i] + b[j] + carry;
            int digit = x % 10;
            carry = x / 10;
            ans.push_back(digit + '0');
            i--;
            j--;
        }
        
        while(i>=0) {
            int x = a[i] + 0 + carry;
            int digit = x % 10;
            carry = x / 10;
            ans.push_back(digit + '0');
            i--;
        }
        
        while(j>=0) {
            int x = 0 + b[j] + carry;
            int digit = x % 10;
            carry = x / 10;
            ans.push_back(digit + '0');
            j--;
        }
        
        if(carry) {
            ans.push_back(carry + '0');
        }
        
        while(ans[ans.size()-1] == '0') {
            ans.pop_back();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
        
    }

int main() {
 
    int A[] = {1, 2}, B[] = {2, 1};
    int n = 2,m = 2;

    string result = calc_Sum(A,n,B,m);
    cout<<"addition is :"<<result<<endl;

return 0;
}