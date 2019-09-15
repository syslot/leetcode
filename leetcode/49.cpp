//
// Created by ningyu on 2019/9/10.
//

#include "../common.h"

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> m;

        for(auto s:strs){
            string s1 = s;
            sort(s1.begin(),s1.end());
            if(m.find(s1) != m.end())
                m[s1].push_back(s);
            else{
                m.insert(make_pair(s1, vector<string>{s}));
            }
        }

        vector<vector<string> > rst;
        for(auto& [k,v]:m)
            rst.push_back(v);

        return rst;
    }
};

int main(){

    vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};

    Solution s;

    auto p = s.groupAnagrams(strs);
    for(auto w:p){
        for(auto s:w)
            cout << s << " ";
        cout << endl;
    }
}