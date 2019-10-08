//
// Created by ningyu on 2019/9/11.
//

#include "../common.h"

//class Solution {
//public:
//    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
//        if(intervals.size() == 0)
//            return vector<vector<int>>{newInterval};
//
//        auto flambda  = [](const vector<int> & a, const vector<int> & b){
//            return a[0]!=b[0]? a[0] < b[0]: a[1]<b[1];
//        };
//
//        intervals.push_back(newInterval);
//        sort(intervals.begin(),intervals.end(), flambda);
//
//        vector<vector<int>> rst{intervals[0]};
//
//        for(int i = 1; i < intervals.size(); i++){
//            auto b = intervals[i][0];
//            auto e = intervals[i][1];
//            int j = 0;
//            bool f = false;
//            bool s = false;
//            while(j< rst.size()){
//                if (b <= rst[j][1] && b >= rst[j][0]){// merge
//                    if(e<= rst[j][1]){
//                        j++;
//                        continue;
//                    }
//                    else {
//                        rst[j][1] = e;
//                        f = true; // Need check
//                        break;
//                    }
//                }
//                j++;
//            }
//            if(j == rst.size() && !(b >= rst.back()[0] && e <= rst.back()[1]))
//                rst.push_back(vector<int>{b,e});
//
//            if(f){
//                while(j < rst.size() - 1){
//                    auto e = intervals[j][1];
//                    if(e < intervals[j+1][0]) { // Not need merge
//                        f = 0;
//                        break;
//                    }else if (e <= intervals[j+1][0]) {
//                        f=0;
//                        rst[j][1] = rst[j+1][1];
//                        rst.erase(rst.begin() + j + 1);
//                        break;
//                    }else{
//                        rst.erase(rst.begin() + j+1);
//                    }
//                    j++;
//                }
//            }
//        }
//
//
//        return rst;
//    }
//};

class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.length() == 0 )
            return 0;

        auto it = s.rfind(' ');
        if(it == string::npos)
            return s.length();
        else
            return (s.length() - it -1);
    }
};

int main(){

//    vector<vector<int> > intervals{{1,3},{6,9}};//{{1,2},{3,5}, {6,7},{8,10},{12, 16}};
//    vector<int> newI {2,5};
//    Solution s;
//    auto rst = s.insert(intervals, newI);
//    for(auto v:rst){
//        cout<< v[0] << " " <<v[1]<<endl;
//    }

      Solution s;
      cout << s.lengthOfLastWord("a");
}