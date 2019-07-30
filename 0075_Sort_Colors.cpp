#include<iostream>
#include<vector>

using namespace std;

class Solution {
    public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = 0, num0 = 0, num2 = 0;
        while(i < n - num2){
            //cout << "i=" << i << " num0=" << num0 << " num2=" << num2 << endl;
            //for(int j = 0; j < n; j++) cout << nums[j] << " ";
            //cout << endl;
            // swap the first 1 and cur 0
            if(nums[i] == 0){
                nums[i++] = 1;
                nums[num0++] = 0;
            }
            // swap the 2 to the last
            else if(nums[i] == 2){
                
                num2++;
                nums[i] = nums[n - num2];
                nums[n - num2] = 2;
            }
            else i++;
        }
        return;                        
    }
};

int main(){
    Solution solve;
    vector<int> input = {2,0,2,1,1,0};
    //vector<int> input = {0,0,0,0};
    //vector<int> input = {1,1,1,1};
    //vector<int> input = {2,2,2,2};

    cout << "Input: " << endl;
    for(int i = 0; i < input.size(); i++) cout << input[i] << " ";
    cout << endl;

    solve.sortColors(input);

    cout << "Output: " << endl;
    for(int i = 0; i < input.size(); i++) cout << input[i] << " ";
    cout << endl;

    return 0;
}
