#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	void dfs(int n, int k, vector<int> &stack, vector<vector<int> > &res){
		if(stack.size() == k){
			vector<int> cur;
			for(int i = 0; i < k; i++){
				cur.push_back(stack[i]);
			}
			res.push_back(cur);
			return;
		}
		if((stack.size() > 0) && (stack.back() >= n)) return;
		int start = 1;
		if(stack.size() > 0) start = stack.back() + 1;
		for(int i = start; i <= n; i++){
			stack.push_back(i);
			dfs(n, k, stack, res);
			stack.pop_back();
		}
		return;
	}
	
	// recursion solution
	vector<vector<int> > combine_recursion(int n, int k){
		vector<vector<int> > res;  
        vector<int> stack;
        dfs(n, k, stack, res);
		return res;
	}
	
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > res;  
        vector<int> stack;
        stack.push_back(1);
		while(true){
			// add combination
			if(stack.size() == k){
				vector<int> cur;
				for(int i = 0; i < k; i++){
					cur.push_back(stack[i]);
				}
				res.push_back(cur);
			}
			// last number could add one
			if(stack.back() < n){
				if(stack.size() == k){
					stack.back()++;
				}
				else{
					stack.push_back(stack.back() + 1);
				}
				continue;
			}
			// backtrace
			if(stack.size() <= 0) break;
			stack.pop_back();
			if(stack.size() <= 0) break;
			stack.back()++;
		}
		return res;
    }
};

int main(){
	int n = 4;
	int k = 2;
	vector<vector<int> > res;
	Solution solve;
	res = solve.combine(n, k);
	for(int i = 0; i < res.size(); i++){
		for(int j = 0; j < res[i].size(); j++){
			std::cout << res[i][j] << " ";
		}
		std::cout << std::endl;
	}
	return 0;
} 
