#include<iostream>
using namespace std;

void solve(int N) {
    if(N == 0) { // base case - stop further call
        return;
    }

    cout<<N<<" "; // some processing 
    solve(N-1);
}

int main() {
    solve(5);
return 0;
}