#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<vector<int> > > maps;
        for(int i = 0; i < 9; i++){
            vector<vector<int> > locs;
            maps.push_back(locs);
        }
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.') continue;
                int num = board[i][j] - '1';
                int sub_index = (i / 3) * 3 + (j / 3);
                for(int k = 0; k < maps[num].size(); k++)
                    if((i == maps[num][k][0]) ||
                       (j == maps[num][k][1]) ||
                       (sub_index == maps[num][k][2]))
                        return false;
                vector<int> loc = {i, j, sub_index};
                maps[num].push_back(loc);
            }
        }
        return true;
    }
};

int main(){
    Solution solve;
    vector<vector<char> > input = {
        {'7','3','.','.','7','.','.','.','.'},
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

    cout << "Output: " << solve.isValidSudoku(input) << endl;

    return 0;
}
