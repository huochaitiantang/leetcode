#include "common.hpp" 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] - prices[i - 1] > 0){
                max_profit += prices[i] - prices[i - 1];
            }
        }
        return max_profit;
    }
};

int main(){
    Solution solve;
    //vector<int> v = {7, 1, 5, 3, 6, 4};
    //vector<int> v = {1, 2, 3, 4, 5};
    vector<int> v = {7, 6, 4, 3, 1};
    std::cout << solve.maxProfit(v) << std::endl;
    return 0;
}
