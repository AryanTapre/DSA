// leetcode: 1776
// Car Fleet 2

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<double> getCollisionTimes(vector<vector<int>> &cars) {
    vector<double> ans(cars.size(),-1);
    stack<int> st;
    st.push(cars.size()-1);

    for(int i=cars.size()-1; i>=0; --i) {
        while(!st.empty() && cars[i][1] <= cars[st.top()][1]) {
            st.pop();
        }
        
        if(!st.empty()) {
            while(!st.empty()) {
                double collisionTime = (cars[st.top()][0] - cars[i][0]) / double(cars[i][1] - cars[st.top()][1]);
                if(ans[st.top()] == -1 || collisionTime < ans[st.top()]) {
                    ans[i] = collisionTime;
                    break;
                }
                st.pop();
            }
            // google.com
        }

        st.push(i);
    }
    return ans;
}

int main() {

    vector<vector<int>> cars = {{3,4},{5,4},{6,3},{9,1}};
    vector<double> times = getCollisionTimes(cars);
    for(auto i : times) cout<<i <<" ";
    cout<<endl;

return 0;
}


