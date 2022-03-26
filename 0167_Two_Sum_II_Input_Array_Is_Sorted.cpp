#include "common.hpp"

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low = 1;
        int high = numbers.size();
        int tmp;
        while(low < high){
            tmp = numbers[low - 1] + numbers[high - 1];
            if(tmp == target) return {low, high};
            else if(tmp < target) low++;
            else high--;
        }
        return {1, 1};
    }
};

int main(){
    Solution solve;
    //vector<int> numbers = {2, 7, 11, 15};
    //int target = 9;
    //vector<int> numbers = {2, 3, 4, 5};
    //int target = 6;
    vector<int> numbers = {-1, 0};
    int target = -1;
    vector<int> ans = solve.twoSum(numbers, target);
    for(auto x: ans) cout << x << " ";
    cout << endl;
    return 0;
}
