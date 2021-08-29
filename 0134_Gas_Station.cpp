#include "common.hpp" 


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int i, j, k, cur_gas, n = gas.size();
        for(i = 0; i < n;){
            cur_gas = 0;
            for(j = 0; j < n; j++){
                k = (j + i) % n;
                cout << "Node:" << k << " cur_gas:" << cur_gas << endl;
                if(cost[k] > cur_gas + gas[k]) break;
                cur_gas = cur_gas + gas[k] - cost[k];
            }
            // find the answer
            if(j >= n) return i;
            if(k == i) i++;
            else if(k > i) i = k;
            else break;
        }
        return -1;
    }
};

int main(){
    Solution solve;
    //vector<int> gas = {1, 2, 3, 4, 5};
    //vector<int> cost = {3, 4, 5, 1, 2};
    vector<int> gas = {2, 3, 4};
    vector<int> cost = {3, 4, 3};
    cout << solve.canCompleteCircuit(gas, cost) << endl;
    return 0;
}
