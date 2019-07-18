#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> output;
        if(matrix.size() == 0) return output;
        int i, j, k, m, n, circle;
        m = matrix.size();
        n = matrix[0].size();
        circle = min((n + 1) / 2, (m + 1) / 2);

        for(i = 0; i < circle; i++){
            // from left to right
            for(k = i, j = i; j < n - i; j++){
                output.push_back(matrix[k][j]);
            }
            if(++k < m - i){
                // from up to down
                for(j--; k < m - i; k++)
                output.push_back(matrix[k][j]);
                // from right to left
                j--;
                if(j >= i && j < n - i - 1){
                    for(k--; j >= i; j--)
                    output.push_back(matrix[k][j]);
                    // from down to up
                    for(j++, k--; k > i; k--)
                    output.push_back(matrix[k][j]);
                }
            }
        }
        return output;
    }
};

int main(){
    Solution solve;
    vector<vector<int> > input;
    int cnt = 1, m = 4, n = 3;

    cout << "Input: " << endl;
    for(int i = 0; i < m; i++){
        vector<int> row;
        for(int j = 0; j < n; j++){
            cout << cnt << " ";
            row.push_back(cnt++);
        }
        cout << endl;
        input.push_back(row);
    }
    
    vector<int> output = solve.spiralOrder(input);
    
    cout << "Output: " << endl;
    for(int i = 0; i < output.size(); i++)
        cout << output[i] << " ";
    cout << endl;

    return 0;
}
