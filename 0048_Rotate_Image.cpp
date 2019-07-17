#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n; i++){
            for(int j = i; j < n - 1 - i; j++){
                /*swap evey four location
                   (i, j)    ->    (j, n-1-i)
                     |                 |
                (n-1-j, i) <- (n-1-i, n-1-j)*/
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = tmp;
            }
        }
    }
};

int main(){
    Solution solve;
    /*
    vector<vector<int> > input = {{1, 2, 3},
                                  {4, 5, 6},
                                  {7, 8, 9}};
    */
    vector<vector<int> > input = {{5, 1, 9, 11},
                                  {2, 4, 8, 10},
                                  {13, 3, 6, 7},
                                  {15, 14, 12, 16}};
    

    cout << "Input: " << endl;
    for(int i = 0; i < input.size(); i++){
        for(int j = 0; j < input[i].size(); j++)
            cout << input[i][j] << " ";
        cout << endl;
    }

    solve.rotate(input);

    cout << "Output: " << endl;
    for(int i = 0; i < input.size(); i++){
        for(int j = 0; j < input[i].size(); j++)
            cout << input[i][j] << " ";
        cout << endl;
    }

    return 0;
}
