#include<iostream>
#include<vector>
#include<algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); i++){
            m[nums[i]] = i;
        }
        for(int i = 0; i < nums.size(); i++){
            int rest = target - nums[i];
            if((m.find(rest) != m.end()) && (m[rest] != i)){
                return {i, m[rest]};
            }
        }
        return {};
    }
};

int main(){
    Solution solve;
    vector<int> input = {2, 7, 11, 15};
    int target = 9;
    //vector<int> input = {3, 2, 4};
    //int target = 6;

    cout << "Input: " << endl;
    for(int i = 0; i < input.size(); i++) cout << input[i] << " ";
    cout << endl;

    vector<int> output = solve.twoSum(input, target);

    cout << "Output: " << endl;
    for(int i = 0; i < output.size(); i++)
        cout << output[i] << " ";
    cout << endl;
    return 0;
}
