#include "../common.h"

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        if(s.length() < 4)
            return rst;
        dfs(s, 0);
        return rst;
    }

    void dfs(string s, int depth){
        if(depth == 4){
            if(s.length() == 0) {
                string ss = s_[0] + '.' + s_[1] + '.' + s_[2] + '.' + s_[3];
                rst.push_back(ss);
            }
            return;
        }

        for(auto it = s.begin()+1; it-s.begin() <=3 && it <= s.end() ;it++){
            string ss(s.begin(), it);
            int tmp = atoi(ss.c_str());
            if(tmp <=255){
                if(ss[0] == '0' && ss.length() != 1)
                    continue;
                s_.push_back(ss);
                dfs(string(it, s.end()), depth + 1);
                s_.pop_back();
            }
        }

    }
    vector<string> s_;

    vector<string> rst;
};

int main(){

    string s = "010010";
    Solution ss;
    auto w = ss.restoreIpAddresses(s);

    for(auto r:w)
        cout << r << endl;

}
