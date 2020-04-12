#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    // O(n)
    int largestRectangleArea(vector<int>& heights){
        int h, w, i = 0, res = 0, n = heights.size();
        stack<int> s;
        while(i < n){
            // stack store the non-decreased sequence
            if(s.empty() || heights[s.top()] <= heights[i]){
                s.push(i);
                i++;
            }
            else{
                h = heights[s.top()];
                s.pop();
                w = s.empty()? i : i - s.top() - 1;
                if(h * w > res) res = h * w;
            }
        }
        while(!s.empty()){
            h = heights[s.top()];
            s.pop();
            w = s.empty()? i : i - s.top() - 1;
            if(h * w > res) res = h * w;
        }
        return res;
    }
    
    
    //O(n^2) not pass for the last two tests 
    int largestRectangleArea1(vector<int>& heights) {
        int n = heights.size();
        int res = 0;
        vector<vector<int>> a(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            a[i][i] = heights[i];
            if(a[i][i] > res) res = a[i][i];
        }
        for(int i = 1; i < n; i++){
            for(int j = 0; j < n - i; j++){
                a[j][j+i] = std::min(heights[j+i], a[j][j+i-1]);
                int val = a[j][j+i] * (i + 1);
                if(res < val) res = val;
                //std::cout << x << "," << y << ":" << a[x][y] << std::endl;
            }
        }
        return res;
    }
};

int main(){
    vector<int> heights = {2,1,5,6,2,3};
    //vector<int> heights = {1};
    Solution solve;
    std::cout << solve.largestRectangleArea(heights) << std::endl;
    
} 
