// print all sub-arrays using recurison

#include<iostream>
#include<vector>
using namespace std;


void printElements(vector<int>source, int start, int end) {
    for(int i=start; i<=end; i++) {
        cout<<source.at(i)<<" ";
    }
}

void print(vector<int> &a, int start, int end) {
    if(end >= a.size()) {
        return;
    }

    printElements(a, start, end);   
    cout<<endl;

    print(a, start, end+1);
}

void printSubArrays(vector<int> &a) {
    for(int start=0; start<a.size(); start++) {
        int end = start;
        print(a, start,end);
        cout<<endl;
    }
}

int main() {
    vector<int> a = {1,2,3,4,5};
    printSubArrays(a);
return 0;
}
