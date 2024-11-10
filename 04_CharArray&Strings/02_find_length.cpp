// finding the lenght of a String
#include<iostream>
using namespace std;
 
int getLength(char input[]) {
    int length = 0;
    int index = 0;

    while(input[index] != '\0') {
        ++length;
        ++index;
    }
    return length;
}

int main() {
 
    char data[100];
    cout<<"give me some input < 100 characters:"<<endl;
    cin.getline(data,100);

    cout<<endl<<"length is : "<<getLength(data)<<endl;

return 0;
}