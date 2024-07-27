// leetcode 121

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;


bool isProfit(int buyStockPrice, int sellStockPrice) {
    return (sellStockPrice - buyStockPrice > 0) ? true : false; 
}

int solveRE(vector<int> &prices, int i, int &profit, int &mini_buy_stock) {
        if(i >= prices.size()) return profit;

        if(!isProfit(mini_buy_stock, prices[i])) {
            mini_buy_stock = prices[i];
        } else {
            int profit_tmp = prices[i] - mini_buy_stock;
            if(profit_tmp > profit) profit = profit_tmp; 
        }

        return solveRE(prices,i+1,profit,mini_buy_stock);
    }

int maxProfit(vector<int> &prices) {
    int profit = 0;
    int mini_stock_buy = INT_MAX;

    return solveRE(prices, 0, profit, mini_stock_buy);
}

int main() {

   vector<int> prices = {7,1,5,3,6,4};

   cout<<"max profit is : "<<maxProfit(prices)<<endl; 

return 0;
}