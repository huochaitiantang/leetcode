#include<iostream>
#include<vector>

using namespace std;

class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int m = matrix.size();
            if(m == 0) return false;
            int n = matrix[0].size();
            if(n == 0) return false;
            
            // binary search for row
            int low = 0, mid, high = m - 1;
            while(low <= high){
                mid = (low + high) / 2;
                if(matrix[mid][0] > target) high = mid - 1;
                else if(matrix[mid][n - 1] < target) low = mid + 1;
                else break;
            }
            if(!(matrix[mid][0] <= target && matrix[mid][n - 1] >= target))
                return false;
            int row = mid;
            low = 0;
            high = n - 1;
            while(low <= high){
                mid = (low + high) / 2;
                if(matrix[row][mid] > target) high = mid - 1;
                else if(matrix[row][mid] < target) low = mid + 1;
                else return true;
            }
            return false;
        }
};

int main(){
    Solution solve;
    int target = 16;
    vector<vector<int> > input = {{1,3,5,7},
                                  {10,11,16,20},
                                  {23,30,34,50}};
    cout << "Input: " << endl;
    for(int i = 0; i < input.size(); i++){
        for(int j = 0; j < input[i].size(); j++)
            cout << input[i][j] << " ";
        cout << endl;
    }

    cout << "Ouptut: " << solve.searchMatrix(input, target) << endl;

    return 0;
}
