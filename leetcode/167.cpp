#include "../common.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int m = target/2;
        for(int i=0;i<numbers.size() && numbers[i] <= m;i++){
            int rst = find(numbers, target-numbers[i], i, numbers.size());
            if(rst != -1){
                return vector<int> {i+1, rst+1};
            }
        }    
        return vector<int>{};
    }

    int find(vector<int>& numbers, int a, int l, int r){
        if(l>=r)
            return -1;
        int mid = (l+r)/2;
        if(numbers[mid] == a)
            return mid;
        if(numbers[mid]> a){
            return find(numbers, a, l,mid);
        }else
            return find(numbers, a, mid+1, r);
    }
};

int main(){

    vector<int> nums{2,7,11,15, 18,19, 33};

    int target = 33;
    Solution s;
    auto rst = s.twoSum(nums,target);
    for(auto r:rst)
        cout << r << " ";

}
