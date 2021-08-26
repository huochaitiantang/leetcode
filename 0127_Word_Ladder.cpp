#include "common.hpp"

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

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int res = 0;
        int n = wordList.size();
        if(n <= 0) return res;

        // get index of endWord in wordList
        int i, j, k, end_id = -1;
        for(i = 0; i < n; i++){
            if(get_diff_cnt(endWord, wordList[i]) == 0){
                end_id = i;
                break;
            }
        }
        if(end_id < 0) return res;

        // bfs
        if(get_diff_cnt(beginWord, endWord) == 1) return 2;
        vector<bool> used(n, false);
        vector<int> paths(n, 0);
        queue<int> qs;
        int qsize, cur_id;

        // init queue
        for(i = 0; i < n; i++){
            int tmp = get_diff_cnt(beginWord, wordList[i]);
            if(tmp == 1){
                qs.push(i);
                used[i] = true;
                paths[i] = 2;
            }
            else if(tmp == 0) used[i] = true;
        }
        // level by level
        while(!qs.empty()){
            qsize = qs.size();
            for(i = 0; i < qsize; i++){
                cur_id = qs.front();
                for(j = 0; j < n; j++){
                    if((!used[j]) && (get_diff_cnt(wordList[cur_id], wordList[j]) == 1)){
                        paths[j] = paths[cur_id] + 1;
                        if(j == end_id) return paths[j];
                        qs.push(j);
                        used[j] = true;
                    }
                }
                qs.pop();
            }    
        }
        return res;
    }
};


int main(){
    Solution solve;
    string begin = "hit";
    string end = "cog";
    //vector<string> words = {"hot","dot","dog","lot","log","cog"};
    vector<string> words = {"hot","dot","dog","lot","log"}; 
    /*string begin = "cet";
    string end = "ism";
    vector<string> words = {"kid","tag","pup","ail","tun","woo","erg","luz","brr","gay","sip","kay","per","val","mes","ohs","now","boa","cet","pal","bar","die","war","hay","eco","pub","lob","rue","fry","lit","rex","jan","cot","bid","ali","pay","col","gum","ger","row","won","dan","rum","fad","tut","sag","yip","sui","ark","has","zip","fez","own","ump","dis","ads","max","jaw","out","btu","ana","gap","cry","led","abe","box","ore","pig","fie","toy","fat","cal","lie","noh","sew","ono","tam","flu","mgm","ply","awe","pry","tit","tie","yet","too","tax","jim","san","pan","map","ski","ova","wed","non","wac","nut","why","bye","lye","oct","old","fin","feb","chi","sap","owl","log","tod","dot","bow","fob","for","joe","ivy","fan","age","fax","hip","jib","mel","hus","sob","ifs","tab","ara","dab","jag","jar","arm","lot","tom","sax","tex","yum","pei","wen","wry","ire","irk","far","mew","wit","doe","gas","rte","ian","pot","ask","wag","hag","amy","nag","ron","soy","gin","don","tug","fay","vic","boo","nam","ave","buy","sop","but","orb","fen","paw","his","sub","bob","yea","oft","inn","rod","yam","pew","web","hod","hun","gyp","wei","wis","rob","gad","pie","mon","dog","bib","rub","ere","dig","era","cat","fox","bee","mod","day","apr","vie","nev","jam","pam","new","aye","ani","and","ibm","yap","can","pyx","tar","kin","fog","hum","pip","cup","dye","lyx","jog","nun","par","wan","fey","bus","oak","bad","ats","set","qom","vat","eat","pus","rev","axe","ion","six","ila","lao","mom","mas","pro","few","opt","poe","art","ash","oar","cap","lop","may","shy","rid","bat","sum","rim","fee","bmw","sky","maj","hue","thy","ava","rap","den","fla","auk","cox","ibo","hey","saw","vim","sec","ltd","you","its","tat","dew","eva","tog","ram","let","see","zit","maw","nix","ate","gig","rep","owe","ind","hog","eve","sam","zoo","any","dow","cod","bed","vet","ham","sis","hex","via","fir","nod","mao","aug","mum","hoe","bah","hal","keg","hew","zed","tow","gog","ass","dem","who","bet","gos","son","ear","spy","kit","boy","due","sen","oaf","mix","hep","fur","ada","bin","nil","mia","ewe","hit","fix","sad","rib","eye","hop","haw","wax","mid","tad","ken","wad","rye","pap","bog","gut","ito","woe","our","ado","sin","mad","ray","hon","roy","dip","hen","iva","lug","asp","hui","yak","bay","poi","yep","bun","try","lad","elm","nat","wyo","gym","dug","toe","dee","wig","sly","rip","geo","cog","pas","zen","odd","nan","lay","pod","fit","hem","joy","bum","rio","yon","dec","leg","put","sue","dim","pet","yaw","nub","bit","bur","sid","sun","oil","red","doc","moe","caw","eel","dix","cub","end","gem","off","yew","hug","pop","tub","sgt","lid","pun","ton","sol","din","yup","jab","pea","bug","gag","mil","jig","hub","low","did","tin","get","gte","sox","lei","mig","fig","lon","use","ban","flo","nov","jut","bag","mir","sty","lap","two","ins","con","ant","net","tux","ode","stu","mug","cad","nap","gun","fop","tot","sow","sal","sic","ted","wot","del","imp","cob","way","ann","tan","mci","job","wet","ism","err","him","all","pad","hah","hie","aim","ike","jed","ego","mac","baa","min","com","ill","was","cab","ago","ina","big","ilk","gal","tap","duh","ola","ran","lab","top","gob","hot","ora","tia","kip","han","met","hut","she","sac","fed","goo","tee","ell","not","act","gil","rut","ala","ape","rig","cid","god","duo","lin","aid","gel","awl","lag","elf","liz","ref","aha","fib","oho","tho","her","nor","ace","adz","fun","ned","coo","win","tao","coy","van","man","pit","guy","foe","hid","mai","sup","jay","hob","mow","jot","are","pol","arc","lax","aft","alb","len","air","pug","pox","vow","got","meg","zoe","amp","ale","bud","gee","pin","dun","pat","ten","mob"};
    */
    std::cout << solve.ladderLength(begin, end, words) << std::endl;
    return 0;
} 
