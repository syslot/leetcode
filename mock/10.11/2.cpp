#include <iostream>
#include <vector>
#include <map>
#include <tuple>
#include <string>
#include <limits>
#include <array>
#include <cstdlib>

using namespace std;

int gcd(int a, int b){
    if (a == 0) return b;
    if (b == 0) return a;
    if (!(a & 1) && !(b & 1))
        return gcd(a>>1, b>>1)<<1;
    else if (!(b & 1))
        return gcd(a, b>>1);
    else if (!(a & 1)) return gcd(a>>1, b);
    else return gcd(abs(a - b), min(a, b));

}

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size() <=0)
            return 0;

        map<tuple<int, int>,int> uni_p;
        for(auto & p:points)
            uni_p[make_tuple(p[0],p[1])] ++;

        int most_p = 1;
        vector<tuple<int,int>> keys;
        for(auto &kv : uni_p){
            keys.push_back(kv.first);
            if(kv.second > most_p)
                most_p = kv.second;
        }

        map<string,int> count_p;
        for(int i =0;i<keys.size();i++){
            count_p.clear();
            for(int j=i+1;j<keys.size();j++){
                auto p1 = keys[i], p2= keys[j];
                int x = get<0>(p1) - get<0>(p2);
                int y = get<1>(p1) - get<1>(p2);

                int g = gcd(abs(x),abs(y));
                string k = to_string(abs(x)/g) + '/' + to_string(abs(y)/g);
                if(x<0 && y >0 || x>0 && y<0)
                    k = '-' + k;

                if(count_p.find(k) == count_p.end()){
                    count_p[k] = uni_p[keys[i]] + uni_p[keys[j]];
                }else{
                    count_p[k] = count_p[k] + uni_p[keys[j]];
                }
            }
            for(auto & kv:count_p){
                if(kv.second > most_p)
                    most_p = kv.second;
            }
        }
        
        return most_p;
    }
};


int main(){

    vector<vector<int>> ps{{0,0}, {0,0}};//{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}, {1,4}};
    Solution s;
    cout << s.maxPoints(ps) << endl;

}
