#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
    public:
    vector<int> plusOne(vector<int>& digits) {
        int i, sum, n;
        n = digits.size();
        sum = digits.back() + 1;
        i = n - 1;
        for(i = n - 1; i >= 0; i--){
            sum = digits[i] + 1;
            if(sum >= 10) digits[i] = sum % 10;
            else{
                digits[i] = sum;
                break;
            }
        }
        if(i < 0) digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main(){
    Solution solve;
    vector<int> input = {8,9,1};

    cout << "Input: " << endl;
    for(int i = 0; i < input.size(); i++) cout << input[i] << " ";
    cout << endl;

    vector<int> output = solve.plusOne(input);

    cout << "Output: " << endl;
    for(int i = 0; i < output.size(); i++) cout << output[i] << " ";
    cout << endl;

    return 0;
}
