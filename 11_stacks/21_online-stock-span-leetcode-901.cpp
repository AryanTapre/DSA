// leetcode 901
// online stock span


#include<bits/stdc++.h>
using namespace std;

class StockSpanner {
    private:
        stack<pair<int,int> > st;       // <price,span>
    public:

        int next(int price) {
            int span = 1;
            while(!st.empty() && st.top().first <= price) {
                span += st.top().second;
                st.pop();
            }
            
            st.push({price,span});
            return span;
        }

};

int main() {

    StockSpanner * sp = new StockSpanner();

    cout<<sp->next(100)<<endl;
    cout<<sp->next(80)<<endl;
    cout<<sp->next(60)<<endl;
    cout<<sp->next(70)<<endl;
    cout<<sp->next(60)<<endl;
    cout<<sp->next(75)<<endl;
    cout<<sp->next(85)<<endl;

return 0;
}