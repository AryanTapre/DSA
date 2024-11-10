// leetcode 22
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void solve(int openBrackets, int closeBrackets, string output, vector<string> &answer) {
    if(openBrackets == 0 && closeBrackets == 0) {
        answer.push_back(output);
        return;
    }

    // include open-brackets
    if(openBrackets > 0) {
        output.push_back('(');
        solve(openBrackets-1, closeBrackets, output, answer);

        // backtracking line..
        output.pop_back();
    }

    // include close-brackets
    if(closeBrackets > openBrackets) {
        output.push_back(')');
        solve(openBrackets, closeBrackets-1, output, answer);

        // backtracking line..
        output.pop_back();
    }
}

vector<string> generateParenthesis(int n) {
    int openBrackets = n;
    int closeBrackets = n;
    string output;
    vector<string> answer;

    solve(openBrackets, closeBrackets, output, answer);
    return answer;
}

int main() {

    vector<string> ways = generateParenthesis(1);
    for(auto i : ways) {
        cout<<i<<endl;
    }
    cout<<endl;

return 0;
}