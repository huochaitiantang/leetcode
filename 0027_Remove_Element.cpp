#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i, output = 0;
        int size = nums.size();
        for(i = 0; i < size; i++){
            if(nums[i] == val) while((i < size) && (nums[i] == val)) i++;
            if(i < size){
                nums[output] = nums[i];
                output++;
            }
        }
        return output; 
    }
};

int main(){
    Solution solve;
    vector<int> input = {0,1,2,2,3,0,4,2};
    int val = 2;

    cout << "Input: val=" << val << endl;
    for(int i = 0; i < input.size(); i++) cout << input[i] << " ";
    cout << endl;

    int output = solve.removeElement(input, val);
    cout << "Output:" << endl;
    for(int i = 0; i < output; i++) cout << input[i] << " ";
    cout << endl;


}
