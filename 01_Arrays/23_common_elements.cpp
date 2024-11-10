//TODO: common elements gfg practice:
#include<vector>
#include<set>
#include<iostream>
using namespace std;
 
vector<int> common_elements(vector<int> a, vector<int> b,vector<int> c) {
    int i,j,k;
    i = j = k = 0;
    vector<int> temp;
    set<int> st;

    while(i < a.size() && j < b.size() && k < c.size()) {
        if(a[i] == b[j] && b[j] == c[k]) {
            st.insert(a[i]);
            i++,j++,k++;
        }
        else if(a[i] < b[j]) {
            i++;
        }
        else if(b[j] < c[k]) {
            j++;
        }
        else {
            k++;
        }        
    }

    for(auto x : st) {
        temp.push_back(x);
    }
    return temp;
}

int main() {
 
    vector<int> a = {3,3,3};
    vector<int> b = {3,3,3};
    vector<int> c = {3,3,3};

    vector<int> ans = common_elements(a,b,c);
    
    for(auto x: ans) {
        cout<<x<<" ";
    }

return 0;
}