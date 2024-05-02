// Convert letters to upper and lower case respectively.
#include<iostream>
#include<string.h>
using namespace std;

void toUpperCase(char word[]) {
    for(int i=0; i<strlen(word); i++) {
        if(word[i] == ' ') {
            continue;
        }
        
        if(word[i] + 32 > 122) { // word[i] is in lower case
            word[i] = word[i] - 32;
        }
    }
}

void toLowerCase(char word[]) {
    for(int i=0; i<strlen(word); i++) {
        if(word[i] == ' ') {
            continue;
        }
        if(word[i] + 32 <= 122) { // word[i] is in uppercase
            word[i] = word[i] + 32;
        }
    }
}

int main() {
 
    char word[100];
    cout<<"Enter a word:"<<endl;
    cin.getline(word,100);
    toLowerCase(word);
    //toUpperCase(word);
    cout<<endl<<"lowercase form is:"<<word<<endl;

return 0;
}