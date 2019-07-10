#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i, j, k, val;
        int size = nums.size();
        // from the end, found the first number that < its next;
        for(i = size - 2; i >= 0; i--){
            if(nums[i] < nums[i + 1]){
                j = i + 1;
                // find the min val it <, swap
                while((j < size) && (nums[j] > nums[i])) j++;
                val = nums[i];
                nums[i] = nums[j - 1];
                nums[j - 1] = val;
                break;
            }
        }
        // reverse the rest
        for(j = i + 1, k = nums.size() - 1; j < k; j++, k--){
            val = nums[j];
            nums[j] = nums[k];
            nums[k] = val;
        }
        return;
    }
};


int main(){
    Solution solve;
    //vector<int> input = {2, 3, 1};
    //vector<int> input = {5, 4, 7, 5, 3, 2};
    vector<int> input = {4, 2, 0, 2, 3, 2, 0};

    cout << "Input: " << endl;
    for(int i = 0; i < input.size(); i++) cout << input[i] << " ";
    cout << endl;

    solve.nextPermutation(input);

    cout << "Output: " << endl;
    for(int i = 0; i < input.size(); i++) cout << input[i] << " ";
    cout << endl;

    return 0;
}
