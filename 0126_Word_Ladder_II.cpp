#include "common.hpp"
#include <unordered_set> 

class Solution {
public:
    // 0: same, 1: 1 char different, 2: >=2 chars different
    int get_diff_cnt(string s1, string s2){
        int diff_cnt = 0;
        for(int i = 0; i < s1.size(); i++){
            if(s1[i] != s2[i]){
                diff_cnt += 1;
                if(diff_cnt > 1) return 2;
            }
        }
        return diff_cnt;
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        short n = wordList.size();
        if(n <= 0) return res;

        // get index of endWord in wordList
        short i, j, k, end_id = -1;
        for(i = 0; i < n; i++){
            if(get_diff_cnt(endWord, wordList[i]) == 0){
                end_id = i;
                break;
            }
        }
        if(end_id < 0) return res;

        // get ids of connection items for wordList[i]
        vector<vector<short>> conns(n, vector<short>());
        for(i = 0; i < n; i++){
            for(j = i + 1; j < n; j++){
                if(get_diff_cnt(wordList[i], wordList[j]) == 1){
                    conns[i].push_back(j);
                    conns[j].push_back(i);
                }
            }
        }

        // bfs
        vector<bool> used(n, false);
        vector<vector<vector<short>>> paths(n, vector<vector<short>>());
        queue<int> qs;
        int qsize, cur_id;
        // init queue
        for(i = 0; i < n; i++){
            int tmp = get_diff_cnt(beginWord, wordList[i]);
            if(tmp == 1){
                qs.push(i);
                vector<short> tmp = {-1, i};
                paths[i].push_back(tmp);
                used[i] = true;
            }
            else if(tmp == 0){
                used[i] = true;
            }
        }
        if(paths[end_id].size() > 0){
            vector<string> tmp = {beginWord, endWord};
            res.push_back(tmp);
            return res;
        }

        while(!qs.empty()){
            qsize = qs.size();
            unordered_set<short> new_ids;
            // level by level
            for(i = 0; i < qsize; i++){
                cur_id = qs.front();
                // collect new ids (cur_id connected ids)
                for(auto conn_id: conns[cur_id]){
                    if(!used[conn_id]){
                        new_ids.insert(conn_id);
                        // collect all previous paths
                        for(k = 0; k < paths[cur_id].size(); k++){
                            vector<short> tmp;
                            tmp.insert(tmp.end(), paths[cur_id][k].begin(), paths[cur_id][k].end());
                            tmp.push_back(conn_id);
                            paths[conn_id].push_back(tmp);
                        }
                    }
                }
                qs.pop();
            }
            // if end_id in new_ids in current level, should return
            if(paths[end_id].size() > 0){
                for(k = 0; k < paths[end_id].size(); k++){
                    vector<string> tmp;
                    for(i = 0; i < paths[end_id][k].size(); i++){
                        cur_id = paths[end_id][k][i];
                        if(cur_id < 0) tmp.push_back(beginWord);
                        else tmp.push_back(wordList[cur_id]);
                    }
                    res.push_back(tmp);
                }
                return res;
            }
            else{
                for(auto new_id: new_ids){
                    used[new_id] = true;
                    qs.push(new_id);
                }
            }
        }
        return res;
    }
};

int main(){
    Solution solve;
    /*
    string begin = "hit";
    string end = "cog";
    vector<string> words = {"hot","dot","dog","lot","log","cog"};
    // vector<string> words = {"hot","dot","dog","lot","log"};
    */
    
    string begin = "hot";
    string end = "dog";
    vector<string> words = {"hot","cog","dog","tot","hog","hop","pot","dot"};

    /*
    string begin = "red";
    string end = "tax";
    vector<string> words = {"ted","tex","red","tax","tad","den","rex","pee"};
    */
    /*
    string begin = "cet";
    string end = "ism";
    vector<string> words = {"kid","tag","pup","ail","tun","woo","erg","luz","brr","gay","sip","kay","per","val","mes","ohs","now","boa","cet","pal","bar","die","war","hay","eco","pub","lob","rue","fry","lit","rex","jan","cot","bid","ali","pay","col","gum","ger","row","won","dan","rum","fad","tut","sag","yip","sui","ark","has","zip","fez","own","ump","dis","ads","max","jaw","out","btu","ana","gap","cry","led","abe","box","ore","pig","fie","toy","fat","cal","lie","noh","sew","ono","tam","flu","mgm","ply","awe","pry","tit","tie","yet","too","tax","jim","san","pan","map","ski","ova","wed","non","wac","nut","why","bye","lye","oct","old","fin","feb","chi","sap","owl","log","tod","dot","bow","fob","for","joe","ivy","fan","age","fax","hip","jib","mel","hus","sob","ifs","tab","ara","dab","jag","jar","arm","lot","tom","sax","tex","yum","pei","wen","wry","ire","irk","far","mew","wit","doe","gas","rte","ian","pot","ask","wag","hag","amy","nag","ron","soy","gin","don","tug","fay","vic","boo","nam","ave","buy","sop","but","orb","fen","paw","his","sub","bob","yea","oft","inn","rod","yam","pew","web","hod","hun","gyp","wei","wis","rob","gad","pie","mon","dog","bib","rub","ere","dig","era","cat","fox","bee","mod","day","apr","vie","nev","jam","pam","new","aye","ani","and","ibm","yap","can","pyx","tar","kin","fog","hum","pip","cup","dye","lyx","jog","nun","par","wan","fey","bus","oak","bad","ats","set","qom","vat","eat","pus","rev","axe","ion","six","ila","lao","mom","mas","pro","few","opt","poe","art","ash","oar","cap","lop","may","shy","rid","bat","sum","rim","fee","bmw","sky","maj","hue","thy","ava","rap","den","fla","auk","cox","ibo","hey","saw","vim","sec","ltd","you","its","tat","dew","eva","tog","ram","let","see","zit","maw","nix","ate","gig","rep","owe","ind","hog","eve","sam","zoo","any","dow","cod","bed","vet","ham","sis","hex","via","fir","nod","mao","aug","mum","hoe","bah","hal","keg","hew","zed","tow","gog","ass","dem","who","bet","gos","son","ear","spy","kit","boy","due","sen","oaf","mix","hep","fur","ada","bin","nil","mia","ewe","hit","fix","sad","rib","eye","hop","haw","wax","mid","tad","ken","wad","rye","pap","bog","gut","ito","woe","our","ado","sin","mad","ray","hon","roy","dip","hen","iva","lug","asp","hui","yak","bay","poi","yep","bun","try","lad","elm","nat","wyo","gym","dug","toe","dee","wig","sly","rip","geo","cog","pas","zen","odd","nan","lay","pod","fit","hem","joy","bum","rio","yon","dec","leg","put","sue","dim","pet","yaw","nub","bit","bur","sid","sun","oil","red","doc","moe","caw","eel","dix","cub","end","gem","off","yew","hug","pop","tub","sgt","lid","pun","ton","sol","din","yup","jab","pea","bug","gag","mil","jig","hub","low","did","tin","get","gte","sox","lei","mig","fig","lon","use","ban","flo","nov","jut","bag","mir","sty","lap","two","ins","con","ant","net","tux","ode","stu","mug","cad","nap","gun","fop","tot","sow","sal","sic","ted","wot","del","imp","cob","way","ann","tan","mci","job","wet","ism","err","him","all","pad","hah","hie","aim","ike","jed","ego","mac","baa","min","com","ill","was","cab","ago","ina","big","ilk","gal","tap","duh","ola","ran","lab","top","gob","hot","ora","tia","kip","han","met","hut","she","sac","fed","goo","tee","ell","not","act","gil","rut","ala","ape","rig","cid","god","duo","lin","aid","gel","awl","lag","elf","liz","ref","aha","fib","oho","tho","her","nor","ace","adz","fun","ned","coo","win","tao","coy","van","man","pit","guy","foe","hid","mai","sup","jay","hob","mow","jot","are","pol","arc","lax","aft","alb","len","air","pug","pox","vow","got","meg","zoe","amp","ale","bud","gee","pin","dun","pat","ten","mob"};
    */
    
    vector<vector<string>> res = solve.findLadders(begin, end, words);
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++) std::cout << res[i][j] << " ";
        std::cout << std::endl;
    }
    return 0;
    
}
