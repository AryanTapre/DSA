#include<vector>
#include<iostream>
using namespace std;
 
int main() {
 
    // creating 4*3 vector
    vector<vector<int> > data;

    vector<int> a = {1,2,3};
    vector<int> b = {4,5,6};
    vector<int> c = {7,8,9};
    vector<int> d = {10,11,12};

    data.insert(data.begin(),a);
    data.insert(data.begin()+1,b);
    data.insert(data.begin()+2,c);
    data.insert(data.begin()+3,d);

    for(int i = 0; i < data.size(); i++) {
        for(int j = 0; j < data[i].size(); j++) {
            cout<<data.at(i).at(j)<<" ";
        }
        cout<<endl;
    }

    

    // creating 3*3 vector
    cout<<endl<<endl;
    int rows = 3, cols = 3;
    vector<vector<int> > v(rows,vector<int>(cols,0));

    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v[i].size(); j++) {
            cout<<v.at(i).at(j)<<" ";
        }
        cout<<endl;
    }
    
return 0;
}