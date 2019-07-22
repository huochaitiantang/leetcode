#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > output(n, vector<int>(n, 0));
        int i, j, k, cnt = 1, circle = (n + 1) / 2;
        for(i = 0; i < circle; i++){
             // left to right
             for(k = i, j = i; j < n - i; j++)
                output[k][j] = cnt++;
             if(++k < n - i){
                // up to down
                for(j--; k < n - i; k++)
                    output[k][j] = cnt++;
                // right to left
                for(j--, k--; j >= i; j--)
                    output[k][j] = cnt++;
                // down to up
                for(j++, k--; k > i; k--)
                    output[k][j] = cnt++;
             }
        }
        return output;
    }
};

int main(){
    Solution solve;
    int input = 5;

    cout << "Input: " << input << endl;

    vector<vector<int> > output = solve.generateMatrix(input);

    cout << "Output: " << endl;
    for(int i = 0; i < output.size(); i++){
        for(int j = 0; j < output[i].size(); j++)
            cout << output[i][j] << " ";
        cout << endl;
    }

    return 0;
}
