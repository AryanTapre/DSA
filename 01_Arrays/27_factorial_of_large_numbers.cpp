// GFG : Factorials of large numbers

#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

vector<int> factorial(int N) {
    vector<int> ans;
    ans.push_back(1);
    int carry = 0;

    for(int i = 2; i <= N; i++) {
        for(int j = 0; j < ans.size(); j++) {
            int x = ans[j] * i + carry;
            int digit = x % 10;
            carry = x / 10;
            ans[j] = digit;
        }

        while(carry) {
            ans.push_back(carry%10);
            carry/=10;
        }
        carry = 0;
    }

    reverse(ans.begin(),ans.end());
    return ans;
}

int main() {
 
    vector<int> result = factorial(1000);
    for(auto i : result) {
        cout<<i<<" ";
    }
    cout<<endl;

return 0;
}