#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int i, output = 0, n = height.size();
        if(n <= 2) return 0;
        vector<int> left_max(n, 0);
        vector<int> right_max(n, 0);

        left_max[0] = height[0];
        for(i = 1; i < n; i++)
            left_max[i] = max(left_max[i - 1], height[i]);

        right_max[n - 1] = height[n - 1];
        for(i = n - 2; i >= 0; i--)
            right_max[i] = max(right_max[i + 1], height[i]);

        // ans[i] = min(max_left, max_right) - height[i]
        for(i = 0; i < n; i++)
            output += min(left_max[i], right_max[i]) - height[i];

        return output;
    }

    int trap1(vector<int>& height) {
        int i, last_h, output = 0, n = height.size();
        if(n <= 0) return 0;

        // save {index, value}
        vector<vector<int> > stack;
        for(i = 0; i < n; i++){
            if(height[i] == 0) continue;
            // find all the <= cur value, add to the output, pop stack
            last_h = 0;
            while((stack.size() > 0) && (height[i] >= stack.back()[1])){
                output += (stack.back()[1] - last_h) * (i - stack.back()[0] - 1);
                last_h = stack.back()[1];
                stack.pop_back();
            }
            // cur value < stack.back, add to the ouput
            if(stack.size() > 0)
                output += (height[i] - last_h) * (i - stack.back()[0] - 1);
            
            vector<int> cur = {i, height[i]};
            stack.push_back(cur);
        }
        return output;
    }
};


int main(){
    Solution solve;
    vector<int> input = {0,1,0,2,1,0,1,3,2,1,2,1};

    cout << "Input:" << endl;
    for(int i = 0; i < input.size(); i++) cout << input[i] << " ";
    cout << endl;

    cout << "Output: " << solve.trap1(input) << endl;

    return 0;
}
