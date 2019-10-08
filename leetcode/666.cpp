#include "../common.h"


bool cmp(const int&a, const int &b){
    if( a/100 < b/100)
        return true;
    else if (a/100 == b/100){
        return (a%100)/10 < (b%100)/10;
    }else
        return false;
}

class Solution {
public:
    int pathSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        map<int, int> tree;
        for(auto & n:nums)
            tree[n/10] = n%10;
        map<int, bool> father;
        int sum =0;
        for(int i = nums.size()-1; i >=0 ;i--){
            int pos = nums[i] /10;
            if(father.find(pos) != father.end())
                continue;
            while(tree.find(pos) != tree.end()){
                father[pos] = true;
                sum += tree[pos];
                pos = (pos/10 - 1) * 10 + ceil(pos%10/2.0);
            }
        }
        return sum;
    }
};

int main(){

    //vector<int> nums{113,215,221};
    vector<int> nums{111,217,221,315,415};
    Solution s;
    cout << s.pathSum(nums) << endl;

}
