// celebrity problem
// GFG practice..

#include<iostream>
#include<vector>
using namespace std;

int celebrity(vector<vector<int>> &m) {
    bool rowContinue = false;
    bool colContinue = false;
    
    for(int c=0; c<m.size(); c++) {
        // row check
        for(int i=0; i<m.size(); i++) {
            if(m[c][i] != 0) {
                cout<<"inside: " <<c<<endl;
                rowContinue = true;
                break;
            }
        }

        if(rowContinue) {
            rowContinue = false;
            continue;
        }

        cout<<"here: "<<c<<endl;
        // col check
        for(int j=0; j<m.size(); j++) {
            if(m[j][c] != 1 && j != c) {
                colContinue = true;
                break;
            }
        }

        if(colContinue) {
            colContinue = false;
            continue;
        }

        return c;
    }
    return -1;
}

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