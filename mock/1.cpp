#include "../common.h"


class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        string s = first + " " + second;
        vector<string> v;
        
        int p = text.find(s);
        while(p != string::npos){
            
        }
    }
};

int main(){
    string str("alice is a good girl she is a good student");
    string w1("a");
    string w2("good");

    Solution s;
    auto r = s.findOcurrences(str, w1, w2);
    for(auto &w:r)
        cout << w << endl;



}
