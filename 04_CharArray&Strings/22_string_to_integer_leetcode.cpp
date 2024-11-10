//leetcode :8
#include<string>
#include<limits.h>
#include<cctype>
#include<iostream>
using namespace std;

int myAtoi(string s) {
    int num = 0;
    int i = 0;
    int sign = 1; //+ve

    while(s[i] == ' ') {
        i++;
    }

    if(i<s.size() && (s[i] == '+' || s[i] == '-')) {
        sign  = s[i] == '+' ? 1 : -1;
        ++i;
    }

    while(i<s.size() && isdigit(s[i])) {
        if(num > INT_MAX/10 || (num == INT_MAX/10 && s[i] > '7')) {
            return sign == 1 ? INT_MAX : INT_MIN;
        }
        num = num * 10 + (s[i] - '0');
        i++;
    }
    return num;
}

int main() {
    string str = "   -1234";
    cout<<myAtoi(str)<<endl;

    // string st = "2002";
    // int x = atoi(st.c_str());
    // cout<<x<<endl;


    // string name = "1000";
    // const char* p = name.c_str();
    // while(p != '\0') {
    //     cout<<*p<<endl;
    //     p++;
    // } 

   

return 0;
}