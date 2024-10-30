// leetcode : find area of largest rectangle in histogram
// leetcode: 84

#include<iostream>
#include<stack>
#include<vector>
#include<limits.h>
using namespace std;

vector<int> prevSmallerElements(vector<int> &inp) {
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
        // replace -1 index with inp.size()
        if(index == -1) index = inp.size();
        ans[i] = index;
        st.push(i);
    }
    return ans;
}

int largestRectangularArea(vector<int> &heights) {
    int maxi = INT_MIN;
    vector<int> prevSmaller = prevSmallerElements(heights);
    vector<int> nextSmaller = nextSmallerElement(heights);

    for(int i=0; i<heights.size(); i++) {
        int length = heights[i];
        int width = nextSmaller[i] - prevSmaller[i] - 1;
        int area = length * width;
        maxi = max(area, maxi);
    }
    return maxi;
}

int main() {

    vector<int> heights = {2,1,5,6,2,3};
    cout<<"largest area in units are : "<<largestRectangularArea(heights)<<endl;

return 0;
}