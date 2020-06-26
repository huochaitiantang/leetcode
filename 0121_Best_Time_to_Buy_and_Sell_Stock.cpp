#include "common.hpp"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) return 0; 
        int max_profit = 0, profit;
        int buy_price = prices[0];
        for(int i = 1; i < prices.size();  i++){
            if(prices[i] < buy_price) buy_price = prices[i];
            profit = prices[i] - buy_price;
            if(profit > max_profit) max_profit = profit;
        }
        return max_profit;
    }
};

int main(){
    Solution solve;
    vector<int> v = {7, 1, 5, 3, 6, 4};
    //vector<int> v = {7, 6, 4, 3, 1};
    std::cout << solve.maxProfit(v) << std::endl;
    return 0;
}
