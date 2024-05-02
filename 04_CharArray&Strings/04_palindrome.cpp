// check input string is palindrome?
#include<string.h>
#include<iostream>
using namespace std;
 
bool isPalindrome(char word[]) {
    int i = 0;
    int j = strlen(word) - 1;
    bool isPalin = true;

    while(i < j) {
        if(word[i] != word[j]) {
            isPalin = false;
            break;
        }
        i++;
        j--;
    }
    return isPalin;
}
 
int main() {
 
    char word[100];
    cout<<"wnter word:"<<endl;
    cin.getline(word,100);

    cout<<endl<<"palindrome result:"<<isPalindrome(word);
return 0;
}