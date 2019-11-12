#include "../common.h"

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 0 || height.size() == 1)
            return 0;

        int sum = 0;
        int m_l = height[0], m_r = height.back();

        int idx_l=0,idx_r= height.size()-1;
        while(idx_l <= idx_r){
            m_l = max(m_l, height[idx_l]);
            m_r = max(m_r, height[idx_r]);
            if(m_l < m_r)
                sum += m_l - height[idx_l++];
            else
                sum += m_r - height[idx_r--];
        }
        return sum;
    }
};

int main(){


    vector<int> height{0,1,0,2,1,0,1,3,2,1,2,1};
    Solution s;
    cout << s.trap(height) << endl;
}
