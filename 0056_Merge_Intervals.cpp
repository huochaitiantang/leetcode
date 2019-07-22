#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int> > output;
        int i, start, end, n = intervals.size();

        // sort
        sort(intervals.begin(), intervals.end());

        for(i = 0; i < n; i++){
            start = intervals[i][0];
            end = intervals[i][1];

            // merge next item
            while((i + 1 < n) && (intervals[i + 1][0] <= end)){
                end = max(end, intervals[++i][1]);
            }
            vector<int> tmp = {start, end};
            output.push_back(tmp);
        }
        
        return output;
    }
};

int main(){
    Solution solve;
    //vector<vector<int> > input = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int> > input = {{1,4},{4,5},{5,9}};

    cout << "Input: " << endl;
    for(int i = 0; i < input.size(); i++){
        for(int j = 0; j < input[i].size(); j++)
            cout << input[i][j] << " ";
        cout << endl;
    }

    vector<vector<int> > output = solve.merge(input);

    cout << "Output: " << endl;
    for(int i = 0; i < output.size(); i++){
        for(int j = 0; j < output[i].size(); j++)
            cout << output[i][j] << " ";
        cout << endl;
    }

    return 0;
}
