#include "../common.h"

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<tuple<string,string> > s;

        for(auto & addr:emails){
            int it = addr.find('@');
            string left;
            for(int i =0;i<it;i++){
                if(addr[i] =='.')
                    continue;
                if(addr[i] == '+')
                    break;
                left += addr[i];
            }
            auto cur = make_tuple(left, addr.substr(it+1 , addr.length()- it));
            if(s.find(cur) == s.end()){
                s.insert(cur);
            }
        }
        return s.size();
    }
};

int main(){

    vector<string> emails{"test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"};

    Solution s;
    cout << s.numUniqueEmails(emails) << endl;;


}
