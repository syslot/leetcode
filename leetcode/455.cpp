#include "../common.h"

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int c=0;
        auto it_g = g.begin();
        auto it_s = s.begin();
        while(it_g < g.end() && it_s < s.end()){
            if(*it_g <= *it_s){
                c++;
                it_g ++;
                it_s ++;
            }else{
                it_s++;
            }


        }
        return c;
    }
};

int main(){
    vector<int> g{7,9,8,10};
    vector<int> s{5,6,7,8};
    Solution ss;
    cout << ss.findContentChildren(g,s)<<endl;

}
