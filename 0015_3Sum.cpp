#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;

#define MAX 20

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums){
    
        int size = nums.size();
        vector<vector<int> > outputs;

        // sort at first
        sort(nums.begin(), nums.end());

        // the first element should be <= 0
        for(int i = 0; (i < size) && (nums[i] <= 0); i++){
            // in case of duplicate
            if((i > 0) && (nums[i] == nums[i - 1])) continue;
            int low = i + 1;
            int high = size - 1;
            while(low < high){
                int cur_sum = nums[i] + nums[low] + nums[high];
                if(cur_sum > 0){
                    high--;
                }
                else if(cur_sum < 0){
                    low++;
                }
                else{
                    vector<int> tripet;
                    tripet.push_back(nums[i]);
                    tripet.push_back(nums[low++]);
                    tripet.push_back(nums[high--]);
                    outputs.push_back(tripet);
                    while((low < size) && (nums[low] == nums[low - 1])) low++;
                    while((high >= 0) && (nums[high] == nums[high + 1])) high--;

                }
            }
        }
        return outputs;
    }
};


int main (){
    Solution solve;
    vector<int> inputs;
    //vector<int> inputs = {-2, 0, 0, 2, 2};
    //vector<int> inputs = {-1, 0, 1, 2, -1, -4};
    vector<vector<int> > outputs;

    cout << "Inputs: " << endl;
    for(int i = 0; i < 10; i++){
        inputs.push_back((random() % MAX) - (MAX / 2));
        cout << inputs[inputs.size() - 1] << " ";
    }
    cout << endl;

    outputs = solve.threeSum(inputs);

    cout << "Outputs: " << endl;
    for(int i = 0; i < outputs.size(); i++){
        for(int j = 0; j < outputs[i].size(); j++){
            cout << outputs[i][j] << " ";
        }
        cout << endl;
    }

    return 0;

}
