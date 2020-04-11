#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    
    bool dfs(vector<vector<char>>& board, string word, int x, int y, int k, vector<vector<bool>>& visited){
        // no longer to go deeper
        if(k == word.length() - 1) return true;
        visited[x][y] = true;
        char ch = word[k + 1];
        int n = board.size();
        int m = board[0].size();
        if((x - 1 >= 0) && (!visited[x - 1][y]) && (board[x - 1][y] == ch)){
            if(dfs(board, word, x - 1, y, k + 1, visited)) return true;
        }
        if((x + 1 < n) && (!visited[x + 1][y]) && (board[x + 1][y] == ch)){
            if(dfs(board, word, x + 1, y, k + 1, visited)) return true;
        }
        if((y - 1 >= 0) && (!visited[x][y - 1]) && (board[x][y - 1] == ch)){
            if(dfs(board, word, x, y - 1, k + 1, visited)) return true;
        }
        if((y + 1 < m) && (!visited[x][y + 1]) && (board[x][y + 1] == ch)){
            if(dfs(board, word, x, y + 1, k + 1, visited)) return true;
        }
        visited[x][y] = false;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int k = word.length();
        if((n == 0) || (k == 0)) return false;
        int m = board[0].size();
        vector<vector<bool>> visited;
         // init flag
        for(int i = 0; i < n; i++){
            vector<bool> cur(m, false);
            visited.push_back(cur);
        }
        // search by dfs
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if((board[i][j] == word[0]) && (dfs(board, word, i, j, 0, visited))){
                    return true;
                }
            }
        }
        return false;
    }
};

int main(){
    vector<vector<char> > board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}};
    //string word = "ABCCED";
    //string word = "SEE";
    string word = "ABCB";
    Solution solve;
    std::cout << solve.exist(board, word) << std::endl;
    return 0;
} 
