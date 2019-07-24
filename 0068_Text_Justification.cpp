#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
    public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> output;
        int i, j, k, len, n = words.size(), skip, more;
        for(i = 0; i < n;){
            len = words[i].size();
            for(j = i + 1; j < n; j++){
                len += 1 + words[j].size();
                if(len > maxWidth) break;
            }
            if(j < n) len -= words[j].size() + j - i;
            else len -= j - i - 1;
            
            
            if(j - i - 1 > 0){
                // left more space
                if(j < n){
                    skip = (maxWidth - len) / (j - i - 1);
                    more = (maxWidth - len) % (j - i - 1);
                }
                // last line one space between words
                else{
                    skip = 1;
                    more = 0;
                }
            }

            cout << "i=" << i << " j=" << j << " skip=" << skip << " more=" << more << endl;

            string s = words[i];
            for(k = i + 1; k < j; k++){
                string tmp(skip, ' ');
                if(k - i <= more) tmp += ' ';
                s += tmp + words[k];
            }
           
            // pad 0 if not enough to maxWidth
            if(s.size() < maxWidth){
                string tmp(maxWidth - s.size(), ' ');
                s += tmp;
            }

            output.push_back(s);
            i = j;
        }


        return output;
    }
};

int main(){
    Solution solve;
    //vector<string> input = {"This", "is", "an", "example", "of", "text", "justification."};
    //vector<string> input = {"What","must","be","acknowledgment","shall","be"};
    vector<string> input = {"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"};
    int maxWidth = 20;

    cout << "Input: " << endl;
    for(int i = 0; i < input.size(); i++) cout << input[i] << " ";
    cout << endl;

    vector<string> output = solve.fullJustify(input, maxWidth);

    cout << "Output: " << endl;
    for(int i = 0; i < output.size(); i++) cout << output[i] << endl;


    return 0;
}
