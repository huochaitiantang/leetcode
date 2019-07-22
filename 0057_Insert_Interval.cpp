#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int> > output;
        int i, start, end, n = intervals.size(), tmp_start;
        start = newInterval[0];
        end = newInterval[1];

        for(i = 0; i < n; i++){
            if(start <= intervals[i][0] || start <= intervals[i][1]){

                tmp_start = min(start, intervals[i][0]);
                while(i < n && end > intervals[i][1]) i++;
                // end > last
                if(i >= n){
                    vector<int> tmp = {tmp_start, end};
                    output.push_back(tmp);
                }
                // end < last second && > last first
                else if (intervals[i][0] <= end){
                    vector<int> tmp = {tmp_start, intervals[i][1]};
                    output.push_back(tmp);
                    i++;
                }
                // end < last first
                else{
                    vector<int> tmp = {tmp_start, end};
                    output.push_back(tmp);
                }
                break;

            }
            else output.push_back(intervals[i]);
        }

        // rest seg
        for(; i < n; i++) output.push_back(intervals[i]);
        if(n == 0 || intervals.back()[1] < start){
            output.push_back(newInterval);
        }
        return output;
    }
};


int main(){
    Solution solve;
    //vector<vector<int> > input = {{1,3}, {6,9}};
    //vector<int> newI = {2,5};
    //vector<vector<int> > input = {{1,3}, {5,7},{9,11},{13,15}};
    //vector<int> newI = {0,19};
    vector<vector<int> > input = {{1,5}};
    //vecotr<vecotr<int> > input;
    vector<int> newI = {6,8};

    cout << "Input: insert:" << newI[0] << " " << newI[1] << endl;
    for(int i = 0; i < input.size(); i++){
        for(int j = 0; j < input[i].size(); j++)
            cout << input[i][j] << " ";
        cout << endl;
    }

    vector<vector<int> > output = solve.insert(input, newI);

    cout << "Output: " << endl;
    for(int i = 0; i < output.size(); i++){
        for(int j = 0; j < output[i].size(); j++)
            cout << output[i][j] << " ";
        cout << endl;
    }

    return 0;
}
