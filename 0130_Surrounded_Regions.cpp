#include "common.hpp" 

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if(n <= 0) return;
        int m = board[0].size();
        if(m <= 0) return;
        vector<vector<int>> locs;
        int index, x, y;
        bool bound;
        
        vector<vector<bool>> flag(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'X' || flag[i][j] == true) continue;
                // char = 'O' and not visit
                locs.clear();
                locs.push_back({i, j});
                flag[i][j] = true;
                index = 0;
                bound = false;
                // find the all 'O' connect to it
                while(index < locs.size()){
                    y = locs[index][0];
                    x = locs[index][1];
                    
                    if((y <= 0) || (x <= 0) || (y >= n - 1) || (x >= m - 1)) bound = true;
                    if((y > 0) && (!flag[y - 1][x]) && (board[y - 1][x] == 'O')){
                        flag[y - 1][x] = true;
                        locs.push_back({y - 1, x});
                    }
                    if((x > 0) && (!flag[y][x - 1]) && (board[y][x - 1] == 'O')){
                        flag[y][x - 1] = true;
                        locs.push_back({y, x - 1});
                    }
                    if((y < n - 1) && (!flag[y + 1][x]) && (board[y + 1][x] == 'O')){
                        flag[y + 1][x] = true;
                        locs.push_back({y + 1, x});
                    }
                    if((x < m - 1) && (!flag[y][x + 1]) && (board[y][x + 1] == 'O')){
                        flag[y][x + 1] = true;
                        locs.push_back({y, x + 1});
                    }
                    index++;
                }
                // flip the char not in the bound
                if(!bound){
                    for(auto loc: locs) board[loc[0]][loc[1]] = 'X';
                }
            }
        }
        return;
    }
};

int main(){
    Solution solve;
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'O'}
    };
    for(auto lines: board){
        for(auto c: lines)  std::cout << c << " ";
        std::cout << std::endl;
    }
    solve.solve(board);
    std::cout << std::endl;
    for(auto lines: board){
        for(auto c: lines)  std::cout << c << " ";
        std::cout << std::endl;
    }
    return 0;
}
