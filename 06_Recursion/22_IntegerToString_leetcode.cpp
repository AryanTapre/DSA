// Leetcode: 273

#include<iostream>
#include<vector>
using namespace std;

string numberToWords(vector<pair<int,string>> &mapp, int num) {
    if(num == 0) return "Zero";

    for(int i=mapp.size()-1; i>=0; i--) {
        if(num >= mapp[i].first) {
            string a = "";
            if(num >= 100) a = numberToWords(mapp, num / mapp[i].first) + " ";

            string b = mapp[i].second;
            string c = "";

            if(num % mapp[i].first) c = " " + numberToWords(mapp, num % mapp[i].first);

            return a + b + c;
        }
    }
    return  "";
}

int main() {
    vector<pair<int,string>> mapp = {
        {1, "One"},
        {2,"Two"},
        {3, "Three"},
        {4, "Four"},
        {5, "Five"},
        {6, "Six"},
        {7, "Seven"},
        {8, "Eight"},
        {9, "Nine"},
        {10, "Ten"},
        {11, "Eleven"},
        {12, "Twelve"},
        {13, "Thirteen"},
        {14, "Fourteen"},
        {15, "Fifteen"},
        {16, "Sixteen"},
        {17, "Seventeen"},
        {18, "Eighteen"},
        {19, "Nineteen"},
        {20, "Twenty"},
        {30, "Thirty"},
        {40, "Forty"},
        {50, "Fifty"},
        {60, "Sixty"},
        {70, "Seventy"},
        {80, "Eighty"},
        {90, "Ninety"},
        {100, "Hundred"},
        {1000, "Thousand"},
        {1000000, "Million"},
        {1000000000, "Billion"}
    };

    cout<<numberToWords(mapp,2147483647)<<endl;

return 0;
}