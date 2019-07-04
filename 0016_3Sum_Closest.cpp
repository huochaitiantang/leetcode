#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;

#define MAX 20

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
    
        int size = nums.size();
        int min_diff = 100000000;
        int output;

        // sort at first
        sort(nums.begin(), nums.end());
        for(int i = 0; i < size; i++){
            // in case of duplicate
            if((i > 0) && (nums[i] == nums[i - 1])) continue;
            int low = i + 1;
            int high = size - 1;
            while(low < high){
                int cur_sum = nums[i] + nums[low] + nums[high];
                int cur_diff = cur_sum - target;
                if(abs(cur_diff) < min_diff){
                    min_diff = abs(cur_diff);
                    output = cur_sum;
                }
                if(cur_diff > 0) high--;
                else if(cur_diff < 0) low++;
                else return output;
            }
        }
        return output;
    }
};


int main (){
    Solution solve;
    //vector<int> inputs;
    vector<int> inputs = {-1, 2, 1, 4};
    int output;
    int target = 1;

    /*
    cout << "Inputs: " << endl;
    for(int i = 0; i < 10; i++){
        inputs.push_back((random() % MAX) - (MAX / 2));
        cout << inputs[inputs.size() - 1] << " ";
    }
    cout << endl;
    */

    output = solve.threeSumClosest(inputs, target);
    cout << "Output: " << output << endl;

    return 0;

}
