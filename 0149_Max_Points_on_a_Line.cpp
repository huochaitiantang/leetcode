#include "common.hpp"
#include<unordered_map>
#include<unordered_set>

class Solution {
public:
    pair<float, float> cal_line(vector<int> p1, vector<int> p2){
        float x1 = (float)p1[0];
        float y1 = (float)p1[1];
        float x2 = (float)p2[0];
        float y2 = (float)p2[1];
        float k = (y1 - y2) / (x1 - x2);
        float b = 0;
        if(x1 != x2) b = y1 - k * x1;
        else b = x1;
        return {k, b};
    }

    int maxPoints(vector<vector<int>>& points) {
        if(points.size() <= 2) return points.size();
        unordered_map<float, unordered_map<float, unordered_set<int>>> maps;
        int ans = 2;
        for(int i = 0; i < points.size(); i++){
            for(int j = i + 1; j < points.size(); j++){
                pair<float, float> line = cal_line(points[i], points[j]);
                if(maps.find(line.first) == maps.end()){
                    maps[line.first] = unordered_map<float, unordered_set<int>>(); 
                }
                if(maps[line.first].find(line.second) == maps[line.first].end()){
                    maps[line.first][line.second] = unordered_set<int>();
                }
                maps[line.first][line.second].insert(i);
                maps[line.first][line.second].insert(j);
                int cur_size = maps[line.first][line.second].size();
                ans = cur_size > ans ? cur_size : ans;
            }
        }
        return ans;
    }
};

int main(){
    Solution solve;
    vector<vector<int>> points = {{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
    //vector<vector<int>> points = {{1,1},{2,2},{3,3}};
    cout << solve.maxPoints(points) << endl;
    return 0;
}
