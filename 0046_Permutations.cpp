#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int i, j, tmp, n = nums.size();
        vector<vector<int> > output;
        if(n == 0) return output;

        sort(nums.begin(), nums.end());
        while(true){
            output.push_back(nums);
            // backtrace
            for(i = n - 2; i >= 0; i--){
                for(j = n - 1; j > i; j--)
                    if(nums[i] < nums[j]) break;
                if(j > i) break;
            }
            if(i < 0) break;
            // swap
            tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
            // reverse rest
            for(i = i + 1, j = n - 1; i < j; i++, j--){
                tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            }
        }
        return output;
            
    }
};

int main(){
    Solution solve;
    vector<int> input = {1, 2, 3};

    cout << "Input: " << endl;
    for(int i = 0; i < input.size(); i++) cout << input[i] << " ";
    cout << endl;

    vector<vector<int> > output = solve.permute(input);

    cout << "Output:" << endl;
    for(int i = 0; i < output.size(); i++){
        for(int j = 0; j < output[i].size(); j++)
            cout << output[i][j] << " ";
        cout << endl;
    }

    return 0;
}
