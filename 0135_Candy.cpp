#include "common.hpp" 


class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n <= 0) return 0;
        
        vector<short> trend(n, 0); // trend between i and i + 1
        for(int i = 0; i + 1 < n; i++){
            int tmp = ratings[i + 1] - ratings[i];
            if(tmp > 0) trend[i] = 1;
            else if(tmp < 0) trend[i] = -1;
            else trend[i] = 0;
        }

        int ans = 0, i = 0, j, cnt, cur_val = 1;
        while(i + 1 < n){
            j = i;
            if(trend[j] == 1){
                while((trend[j] == 1) && (j + 1 < n)) j++;
                cnt = j - i;
                ans += (1 + cnt) * cnt / 2;
                i = j;
                cur_val = cnt + 1;
            }
            else if(trend[i] == -1){
                while((trend[j] == -1) && (j + 1 < n)) j++;
                cnt = j - i;
                ans += (2 + cnt) * (cnt - 1) / 2;
                cur_val = max(1 + cnt, cur_val);
                ans += cur_val;
                cur_val = 1;
                i = j;
            }
            else{
                while((trend[j] == 0) && (j + 1 < n)) j++;
                cnt = j - i;
                ans += cnt - 1;
                ans += cur_val;
                cur_val = 1;
                i = j;
            }
        }
        ans += cur_val;
        return ans;
    }
};

int main(){
    Solution solve;
    vector<int> ratings = {1, 2, 3, 5, 5, 4, 3, 3, 1};
    //vector<int> ratings = {1, 2, 2};
    cout << solve.candy(ratings) << endl;
    return 0;
}
