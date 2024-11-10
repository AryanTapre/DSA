//Missing elements in an Array with duplicates...

#include<iostream>
#include<array>
#include<algorithm>
using namespace std;
 
void find_missing_negatives_approach(array<int,5> a) {
    for(int i = 0; i < a.size(); i++) {
        int index = abs(a[i]) - 1;
        if(a[index] > 0) {
            a[index] *= -1;
        }
    }

    for(int i = 0; i < a.size(); i++) {
        if(a[i] > 0) {
            cout<<i+1<<" ";
        }
    }
    cout<<endl;
} 

void find_missing_positioning_approach(array<int,5> a) {
   
    int i = 0;
    while(i < a.size()) {
        int index = a[i] - 1;

        if(a[i] != a[index]) {
            swap(a[i],a[index]);
        } else {
            ++i;
        }   
    }

    for(int i = 0; i < a.size(); i++) {
        if(i+1 != a[i] ) {
            cout<<i+1<<" ";
        }
    }
}

int main() {
 
    array<int,5> a = {1,3,3,3,4};

   
   


    find_missing_negatives_approach(a);
    find_missing_positioning_approach(a);

return 0;
}