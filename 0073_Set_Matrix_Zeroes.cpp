#include<iostream>
#include<vector>

using namespace std;


class Solution {
    public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        bool first_j = false;
        if(m == 0) return;
        int n = matrix[0].size();
        // mark the first value
        for(int i = 0; i < m; i++){
            if(matrix[i][0] == 0) first_j = true;
            for(int j = 1; j < n; j++){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        // based on the first value
        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++)
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
        if(matrix[0][0] == 0)
            for(int j = 1; j < n; j++)
                matrix[0][j] = 0;
        if(first_j)
            for(int i = 0; i < m; i++)
                matrix[i][0] = 0;
        return;
    }
};


int main(){
    Solution solve;
    //vector<vector<int> > input = {{1,1,1},{1,0,1},{1,1,1}};
    //vector<vector<int> > input = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    vector<vector<int> > input = {{1,1,1},{0,1,2}};

    cout << "Input: " << endl;
    for(int i = 0; i < input.size(); i++){
        for(int j = 0; j < input[i].size(); j++)
            cout << input[i][j] << " ";
        cout << endl;
    }

    solve.setZeroes(input);

    cout << "Output: " << endl;
    for(int i = 0; i < input.size(); i++){
        for(int j = 0; j < input[i].size(); j++)
            cout << input[i][j] << " ";
        cout << endl;
    }


    return 0;
}
