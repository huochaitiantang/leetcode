#include<iostream>
#include<string>
#include<vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    
    vector<int> findSubstring(string s, vector<string>& words) {
        if((words.size() <= 0) || (s.size() <= 0) ||
           (words.size() * words[0].size() > s.size()))
            return {};

        int i, j, ind;
        int wsize = words.size();
        int slen = s.size();
        int wlen = words[0].size();


        vector<int> output;
        unordered_map<string, int> words_num;
        vector<int> matched_num(wsize, 0);
        vector<int> matched_index(slen, -1);

        // unique words num
        for(int i = 0; i < wsize; i++) words_num[words[i]] += 1;

        // save all the match the words
        for(int i = 0; i < slen; i++){
            string substr = s.substr(i, wlen);
            for(int j = 0; j < wsize; j++){
                if(words[j] == substr){
                    matched_index[i] = j;
                    break;
                }
            }
        }

        // match one by one
        for(i = 0, ind = 0; i < slen; i++){
            if(i - ind == wsize * wlen) output.push_back(ind);
            else{
                int wi = matched_index[i];
                if((wi >= 0) && (matched_num[wi] < words_num[words[wi]])){
                    matched_num[wi]++;
                    i = i + wlen - 1;
                    continue;
                }
            }
            for(j = 0; j < wsize; j++) matched_num[j] = 0;
            i = ind;
            ind++;
        }
        // rest
        if(slen - ind == wsize * wlen) output.push_back(ind);
        return output;
    }
};

int main(){
    Solution solve;
    //string s = "barfoothefoobarman";
    //vector<string> words = {"foo","bar"};
    //string s = "barfoofoobarthefoobarman";
    //vector<string> words = {"bar","foo","the"};
    string s = "wordgoodgoodgoodbestword";
    vector<string> words = {"word","good","best","good"};

    cout << "Input: " << s << endl;
    for(int i = 0; i < words.size(); i++) cout << words[i] << " ";
    cout << endl;

    vector<int> output = solve.findSubstring(s, words);

    cout << "Output: " << endl;
    for(int i = 0; i < output.size(); i++) cout << output[i] << " ";
    cout << endl;


    return 0;
}
