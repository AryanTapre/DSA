// leetcode 85
// maximal rectangle

#include<iostream>
#include<stack>
#include<vector>
#include<limits.h>
using namespace std;

vector<int> prevSmallerElement(vector<int> &inp) {
        vector<int> ans;
        stack<int> st;
        st.push(-1);

        for(int i=0; i<inp.size(); i++) {
            while(st.top() != -1 && inp[st.top()] >= inp[i]) st.pop();
            int index = st.top();
            ans.push_back(index);
            st.push(i);
        }
        return ans;
    }

    vector<int> nextSmallerElement(vector<int> &inp) {
        vector<int> ans(inp.size());
        stack<int> st;
        st.push(-1);

        for(int i=inp.size()-1; i>=0; i--) {
            while(st.top() != -1 && inp[st.top()] >= inp[i]) st.pop();
            int index = st.top();
            if(index == -1) index = inp.size();
            ans.at(i) = index;
            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int maxi = INT_MIN;
        vector<int> prevSmaller = prevSmallerElement(heights);
        vector<int> nextSmaller = nextSmallerElement(heights);

        for(int i=0; i<heights.size(); i++) {
            int length = heights[i];
            int width = nextSmaller[i] - prevSmaller[i] - 1;
            int area = length * width;
            maxi = max(maxi, area);
        }
        return maxi;
    }

    int maximalRectangle(vector<vector<char>>& matrix){
        vector<vector<int>> v;
        int maxi = INT_MIN;

        for(int i=0;i<matrix.size();++i){   
            vector<int> t;
            for(int j=0;j<matrix[i].size();++j){
                t.push_back(matrix[i][j] - '0');
            }
            v.push_back(t);

            if(i == 0){
                maxi = max(maxi, largestRectangleArea(v[i]));
            }else{
                for(int j=0;j<v[i].size();j++){
                    v[i][j] = v[i][j] == 0 ? 0 : v[i][j] + v[i-1][j];
                }
                maxi = max(maxi, largestRectangleArea(v[i]));
            }
        }
        return maxi;
    }

int main() {    
    vector<vector<char>> m;
    m = {{'1','0','1','0','0'},
         {'1','0','1','1','1'},
         {'1','1','1','1','1'},   
         {'1','0','0','1','0'}
        };

    cout<<maximalRectangle(m)<<endl;

return 0;
}