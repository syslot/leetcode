#include "../common.h"

class Solution {
public:
    bool checkPerfectNumber(int num) {
        set<int> s;
        s.insert(1);
        for(int i=2;i<=num/2;i++){
            if(num%i==0)
                s.insert(i);
        }

        int sum=0;
        for(auto it=s.begin();it!=s.end();it++){
            sum+=*it;
        }
        if(sum == num)
            return true;
        else
            return false;
        
    }
};

int main(){

    Solution s;
    cout << s.checkPerfectNumber(1) << endl;


}
