#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;

#define MAX 20

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) { 
    
        int size = nums.size();
        vector<vector<int> > outputs;

        // sort at first
        sort(nums.begin(), nums.end());

        // the first element should be <= target
        for(int i = 0; i < size; i++){
            if((i > 0) && (nums[i] == nums[i - 1])) continue;
            for(int j = i + 1; j < size; j++){
                if((j > i + 1) && (nums[j] == nums[j - 1])) continue;
                int low = j + 1;
                int high = size - 1;
                int sum2 = nums[i] + nums[j];
                while(low < high){
                    int cur_sum = sum2 + nums[low] + nums[high];
                    if(cur_sum > target) high--;
                    else if(cur_sum < target) low++;
                    else{
                        vector<int> quadruplet = {nums[i], nums[j], nums[low++], nums[high--]};
                        outputs.push_back(quadruplet);
                        while((low < size) && (nums[low] == nums[low - 1])) low++;
                        while((high >= 0) && (nums[high] == nums[high + 1])) high--;
                    }
                }
            }
        }
        return outputs;
    }
};


int main (){
    Solution solve;
    vector<int> inputs = {1, 0, -1, 0, 2, -2};
    //vector<int> inputs = {1, -2, -5, -4, -3, 3, 3, 5};
    vector<vector<int> > outputs;
    int target = 0;

    outputs = solve.fourSum(inputs, target);

    cout << "Outputs: " << endl;
    for(int i = 0; i < outputs.size(); i++){
        for(int j = 0; j < outputs[i].size(); j++){
            cout << outputs[i][j] << " ";
        }
        cout << endl;
    }

    return 0;

}
