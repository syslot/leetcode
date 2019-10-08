#include "../common.h"

class Solution {
public:

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

    tuple<int, int> v2t(const vector<int> & v){
        return make_tuple(v[0], v[1]);
    }

    int maxPoints(vector<vector<int>>& points) {
       map<tuple<int,int>, int> map_;
       map<tuple<int,int>, int> union_p;
       for(int i =0;i<points.size();i++)
           union_p[make_tuple(points[i][0], points[i][1])] ++;

       vector<vector<int>> p;
       for(auto &v: union_p){
           vector<int> t;
           t.push_back(get<0>(v.first));
           t.push_back(get<1>(v.first));
           p.push_back(t);
       }
       
       int max_p = -1;
       for(int i =0;i<p.size();i++){
            map_.clear();
            for(int j = i+1;j<p.size();j++){
                int x_res = p[j][0] - p[i][0];
                int y_res = p[j][1] - p[i][1];
                if(x_res == 0){
                    y_res = abs(y_res);
                }else if(y_res == 0){
                    x_res = abs(x_res);
                }else{
                    int t = gcd(abs(x_res), abs(y_res));
                
                    x_res /= t;
                    y_res /= t;
                    if( x_res > 0 && y_res <0 || x_res <0 && y_res >0){
                        x_res = - abs(x_res);
                        y_res = abs(y_res);
                    }else{
                        x_res = abs(x_res);
                        y_res = abs(y_res);
                    }
                }
                auto slope = make_tuple(x_res, y_res);
                if(map_.find(slope) != map_.end())
                    map_[slope] ++;
                else
                    map_[slope] = union_p[v2t(p[i])] + union_p[v2t(p[j])];
            }

            for(auto & n:map_){
                if(n.second > max_p)
                    max_p = n.second;
            }
       }
       return max_p;
    }
    
};

int main(){
//    vector<vector<int>> points{{84,250},{0,0},{1,0},{0,-70},{0,-70},{1,-1},{21,10},{42,90},{-42,-230}};

    vector<vector<int>> points{{0,9},{138,429},{115,359},{115,359},{-30,-102},{230,709},{-150,-686},{-135,-613},{-60,-248},{-161,-481},{207,639},{23,79},{-230,-691},{-115,-341},{92,289},{60,336},{-105,-467},{135,701},{-90,-394},{-184,-551},{150,774}};
//    vector<vector<int>> points{{1,1}, {2,2},{3,3}};
    Solution s;
    cout << s.maxPoints(points) <<endl;

}
