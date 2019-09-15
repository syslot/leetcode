//
// Created by ningyu on 2019/9/11.
//

#include "../common.h"


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool flag = true;
        auto it = digits.rbegin();
        while(flag && it != digits.rend()){
            *it += 1;
            if(*it >= 10){
                *it = 0;
                flag =1;
            } else {
                flag = 0;
                break;
            }
            it++;
        }

        if(flag)
            digits.insert(digits.begin(),1);

        return digits;

    }
};


int main(){
    vector<int> dig{9,9,9};
    Solution s;
    s.plusOne(dig);
    for(auto i: dig)
        cout << i << " ";
    cout << endl;
}