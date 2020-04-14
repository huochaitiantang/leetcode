#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    
    int largestRectHist(vector<int> heights, int n){
        int res = 0, i = 0, h, w;
        stack<int> s;
        while(i < n){
            if(s.empty() || heights[i] >= heights[s.top()]){
                s.push(i);
                i++;
            }
            else{
                h = heights[s.top()];
                s.pop();
                w = s.empty() ? i : i - s.top() - 1;
                if(h * w > res) res = h * w;
            }
        }
        while(!s.empty()){
            h = heights[s.top()];
            s.pop();
            w = s.empty() ? i : i - s.top() - 1;
            if(h * w > res) res = h * w;
        }
        return res;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix){
        if(matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> hist(n, vector<int>(m, 0));
        // init the hist of continuous 1 upper
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == '1')
                    hist[i][j] = i > 0 ? hist[i - 1][j] + 1 : 1;
            }
        }
        int res = 0;
        // each line as a hist
        for(int i = 0; i < n; i++){
            int cur = largestRectHist(hist[i], m);
            if(cur > res) res = cur;
        }
        return res;
    }
    
    int maxCurrent(int x, int y, int m, int n, vector<vector<int>> r){
        int max_r = r[x][y];
        if(max_r == 0) return 0;
        int res = max_r;
        // each iter find the complete rect with n step
        int i = x + 1;
        while(true){
            while((i < n) && (r[i][y] >= max_r)) i++;
            int cur = (i - x) * max_r;
            if(cur > res) res = cur;
            if((i >= n) || (r[i][y] <= 0)) break;
            max_r = r[i][y];
            i++;
        }
        return res;
    }
    
    // not ok for the last 2 tests
    int maximalRectangle1(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(n <= 0) return 0;
        int m = matrix[0].size();
        vector<vector<int>> r(n, vector<int>(m, 0));
        
        // the max continuous length of 1 right
        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = m - 1; j >= 0; j--){
                if(matrix[i][j] == '1'){
                    cnt++;
                    r[i][j] = cnt;
                }
                else cnt = 0;
            }
        }
        
        int res = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int cur = maxCurrent(i, j, m, n, r);
                if(cur > res) res = cur;
            }
        }
        return res;
    }
};

int main(){
    vector<vector<char> > matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}};
    Solution solve;
    std::cout << solve.maximalRectangle(matrix) << std::endl;
  return 0;
}

