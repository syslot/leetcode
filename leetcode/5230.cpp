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

    bool checkStraightLine(vector<vector<int>>& coordinates) {
        
        if(coordinates.size() ==0)
            return false;
    
        if(coordinates.size()<=2)
            return true;


        uint64_t x = coordinates[1][0] - coordinates[0][0];
        uint64_t y = coordinates[1][1] - coordinates[0][1];

        for(int i =2;i<coordinates.size();i++){
            uint64_t x1 = coordinates[i][0] - coordinates[0][0];
            uint64_t y1 = coordinates[i][1] - coordinates[0][1];

            if(x * y1 != y * x1)
                return false;
        }

        return true;

        

        
        


        
    }
};

int main(){

    vector<vector<int>> c{
        {1,1}, {2,2},{3,4},{4,5},{5,6},{7,7}
    };

    Solution s;
    cout << s.checkStraightLine(c)<<endl;

}
