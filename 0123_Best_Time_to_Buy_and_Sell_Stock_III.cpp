#include "common.hpp"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit, buy, sell, n = prices.size();
        if(n <= 1) return 0;
        vector<int> before(n, 0);
        vector<int> after(n, 0);
        
        // the max profit of day 0-i with one transection
        max_profit = 0;
        buy = prices[0];
        for(int i = 1; i < n; i++){
            int cur = prices[i] - buy;
            if(cur < 0) buy = prices[i];
            else if(cur > max_profit) max_profit = cur;
            before[i] = max_profit;
        }
        
        // the max profit of day i-n with one transection
        max_profit = 0;
        sell = prices[n - 1];
        for(int i = n - 2; i >= 0; i--){
            int cur = sell - prices[i];
            if(cur < 0) sell = prices[i];
            else if(cur > max_profit) max_profit = cur;
            after[i] = max_profit;
        }
        
        // max profit
        max_profit = 0;
        for(int i = 0; i < n; i++){
            int cur = before[i] + after[i];
            if(cur > max_profit) max_profit = cur;
        }
        return max_profit;
    }
};

int main(){
    Solution solve;
    //vector<int> v = {3,3,5,0,0,3,1,4};
    //vector<int> v = {1,2,3,4,5};
    //vector<int> v = {7,6,4,3,1};
    vector<int> v = {1, 2};
    std::cout << solve.maxProfit(v) << std::endl;
    return 0;
} 
