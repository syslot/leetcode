#include "common.h"


class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        return Find_Ex(target, array, 0, 0, array.size()-1, array[0].size()-1);
    }

    bool Find_Ex(int target, const vector<vector<int>> & array, int x, int y, int x1, int y1){

        if(x>x1 or y>y1)
            return false;
        int midx = (x+x1)/2;
        int midy = (y+y1)/2;

        if(target == array[midx][midy])
            return true;

        if(target > array[midx][midy])
            return this->Find_Ex(target, array, midx+1, y, x1, y1) || Find_Ex(target, array, x, midy+1, x1, y1);
        else
            return this->Find_Ex(target, array, x,y, midx-1, y1) || Find_Ex(target, array, x,y, x1, midy-1);
        
    }
};

int main(){
    
    Solution s;

    vector<vector<int>> array;

    array.push_back(vector<int> {1,2,8,9});
    array.push_back(vector<int> {2,4,9,12});
    array.push_back(vector<int> {4,7,10,13});
    array.push_back(vector<int> {6,8,10,15});
    
    int t;
    while(cin>>t)
    cout << s.Find(t, array)<< endl;

    

}
