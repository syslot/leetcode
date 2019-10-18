#include "../common.h"

class Solution {
public:
    string simplifyPath(string path) {
        
        vector<string> s_;
        int cur = 0;

        if(path.size() == 0)
            return "/";
        for(int i =1;i<path.length();i++)
            if(path[i] == '/'){
                if(i - cur == 1 || i - cur == 2 && path[i-1] == '.')
                    cur = i;
                else if(i-cur == 3 && path[cur+1] == '.' && path[cur+2]=='.')
                {
                    cur = i;
                    if(s_.size()!=0)
                        s_.pop_back();
                }
                else{
                    string s(path.begin()+cur+1, path.begin()+i);
                    //cout << s << endl;
                    s_.push_back(s);
                    cur = i;
                }
            }

        if(path[path.length()-1] != '/'){
            int i = path.length()-1;
            if(i-cur == 2 && path[i] == '.' && path[i-1] == '.'){
                if(s_.size()!=0)
                    s_.pop_back();
            }
            else if(!(i-cur==1 && path[i] == '.')){
                s_.push_back(string (path.begin()+cur+1, path.end()));
            }




        }

        if (s_.size() == 0)
            return "/";
        string ss;
        for(int i =0;i<s_.size();i++){
            ss += '/' + s_[i];
        }

        return ss;

            



    }
};

int main(){

    string s = "/.../";

    Solution ss;
    cout << ss.simplifyPath(s) << endl;


}
