// celebrity problem
// GFG practice..

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

// TODO: Optimize way TC = O(N) using stacks
int celebrity(vector<vector<int> > &m) {
    stack<int> st;
    // pushing member onto the stack..
    for(int i=0; i<m.size(); i++) {
        st.push(i);
    }

    while(st.size() != 1) {
        int i = st.top(); st.pop();
        int j = st.top(); st.pop();

        if(m[i][j]) { // i knows j i.e j is celebrity
            st.push(j);
        }else {
            st.push(i); // // j knows i i.e i is celebrity
        }
    }

    int celebrity = st.top(); st.pop();

    // entire row of celebrity should be Zero
    for(int i=0; i<m.size(); i++) {
        if(m[celebrity][i] != 0) return -1;
    }

    // entire col should be One, except diagonal
    for(int i=0; i<m.size(); i++) {
        if(m[i][celebrity] != 1 && i != celebrity ) return -1;
    }

    return celebrity;

}



//TODO: brute-force way  TC = O(N*N)
// int celebrity(vector<vector<int>> &m) {
//     bool rowContinue = false;
//     bool colContinue = false;
    
//     for(int c=0; c<m.size(); c++) {
//         // row check
//         for(int i=0; i<m.size(); i++) {
//             if(m[c][i] != 0) {
//                 cout<<"inside: " <<c<<endl;
//                 rowContinue = true;
//                 break;
//             }
//         }

//         if(rowContinue) {
//             rowContinue = false;
//             continue;
//         }

//         cout<<"here: "<<c<<endl;
//         // col check
//         for(int j=0; j<m.size(); j++) {
//             if(m[j][c] != 1 && j != c) {
//                 colContinue = true;
//                 break;
//             }
//         }

//         if(colContinue) {
//             colContinue = false;
//             continue;
//         }

//         return c;
//     }
//     return -1;
// }

int main() {

    int n = 3;
    vector<vector<int> > m(n, vector<int>(n,0));
    int data[] = {0,0,1,0,0,1,1,0,0};

    int x = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            m[i][j] = data[x];
            x++;
        }
    }

    cout<<celebrity(m)<<endl;

return 0;
}