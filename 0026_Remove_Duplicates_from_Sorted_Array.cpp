#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int output = 1;
        if(nums.size() <= 0) return 0;
        for(int i = 1; i < nums.size(); i++)
            if(nums[i] != nums[i - 1]){
                nums[output] = nums[i];
                output++;
            }
        return output; 
    }
};

int main(){
    Solution solve;
    vector<int> input = {0, 0, 1, 2, 2, 2, 3, 4, 4, 4};

    cout << "Input:" << endl;
    for(int i = 0; i < input.size(); i++) cout << input[i] << " ";
    cout << endl;

    int output = solve.removeDuplicates(input);
    cout << "Output:" << endl;
    for(int i = 0; i < output; i++) cout << input[i] << " ";
    cout << endl;


}
