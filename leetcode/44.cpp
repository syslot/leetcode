//
// Created by ningyu on 2019/9/10.
//

#include "../common.h"

class Solution {
public:
    bool isMatch(string s, string p) {

//        int ARRSIZE = 10001;
        int s_l = s.length()+1;
        int p_l = p.length()+1;
        bool dist[1501][5001]={0};
        dist[0][0] = true;

        for(int i = 0; p[i] == '*' && i < p.length(); i++)
            dist[i+1][0] = true;

        for(int i = 0; i < p.length(); i++){
            for(int j = 0; j < s.length(); j++){
                if(p[i] == '?')
                    dist[i+1][j+1] = dist[i][j];
                else if(p[i] == '*')
                    dist[i+1][j+1] = dist[i][j+1] | dist[i+1][j] | dist[i][j];
                else
                    dist[i+1][j+1] = dist[i][j] && (s[j] == p[i]);
            }
        }
        return dist[p.length()][s.length()];

    }
};

int main(){

    string str = "aab";
    string p = "*c*a*b";

    Solution s;
    cout << s.isMatch(str,p)<<endl;

}
