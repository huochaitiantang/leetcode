#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {

        int i, j, num, top = 0;
        vector<vector<bool> > row(9, vector<bool>(9, false));
        vector<vector<bool> > col(9, vector<bool>(9, false));
        vector<vector<bool> > sub(9, vector<bool>(9, false));
        vector<vector<int> > stack;

        // initial
        for(i = 0; i < 9; i++){
            for(j = 0; j < 9; j++){
                if(board[i][j] == '.'){
                    vector<int> loc = {i, j, 0};
                    stack.push_back(loc);
                    continue;
                }
                num = board[i][j] - '1';
                row[i][num] = true;
                col[j][num] = true;
                sub[(i / 3) * 3 + (j / 3)][num] = true;
            }
        }

        if(stack.size() <= 0) return;
        while(true){
            i = stack[top][0];
            j = stack[top][1];
            num = stack[top][2];
            //cout << "i=" << i << " j=" << j << " num=" << num << endl;
            // backtrace
            if(num >= 9){
                top--;
                if(top < 0) break;
                i = stack[top][0];
                j = stack[top][1];
                num = stack[top][2];
                row[i][num] = col[j][num] = sub[(i / 3) * 3 + (j / 3)][num] = false;
                stack[top][2]++;
                continue;
            }
            // not satisfied
            if(row[i][num] || col[j][num] || sub[(i / 3) * 3 + (j / 3)][num]){
                stack[top][2]++;
                continue;
            }
            // satisfied
            board[i][j] = '1' + num;
            row[i][num] = col[j][num] = sub[(i / 3) * 3 + (j / 3)][num] = true;
            if(++top >= stack.size()) break;
            stack[top][2] = 0;
        }
        return;
    }
};

int main(){
    Solution solve;
    vector<vector<char> > input = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    cout << "Input:" << endl;
    for(int i = 0; i < input.size(); i++){
        for(int j = 0; j < input[i].size(); j++)
            cout << input[i][j] << " ";
        cout << endl;
    }

    solve.solveSudoku(input);

    cout << "Output:" << endl;
    for(int i = 0; i < input.size(); i++){
        for(int j = 0; j < input[i].size(); j++)
            cout << input[i][j] << " ";
        cout << endl;
    }
    
    return 0;
}
