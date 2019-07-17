#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.size() <= 0) return 1;
        int i, j, tmp, n = nums.size();
        
        // let location i - 1 save the value i
        for(i = 0; i < n; ){
            // overflow
            if((nums[i] <= 0) || (nums[i] > n)){
                i++;
                continue;
            }
            j = nums[i] - 1;
            if(nums[i] == nums[j]){
                i++;
                continue;
            }
            if((nums[j] <= 0) || (nums[j] > n))
                nums[j] = nums[i++];
            else{
                tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            }
        }

        // first not appear is the missing value
        for(i = 0; i < n; i++){
            if(nums[i] != i + 1)
                return i + 1;
        }
        return i + 1;
    }
};

int main(){
    Solution solve;
    vector<int> input = {2147483647,2147483646,2147483645,3,2,1,-1,0,-2147483648};
    //vector<int> input = {3, 2, 2, 4};

    cout << "Input:" << endl;
    for(int i = 0; i < input.size(); i++) cout << input[i] << " ";
    cout << endl;

    cout << "Output: " << solve.firstMissingPositive(input) << endl;

    return 0;
}
