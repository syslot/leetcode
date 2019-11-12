#include "../common.h"

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        s.push(-1);

        int maxA = 0;
        for(int i=0;i<heights.size();i++){
            while( s.top()!=-1 && heights[s.top()] >= heights[i]){
                int cur = s.top();
                s.pop();
                maxA = max(heights[cur] * (i - s.top() - 1), maxA);
            }
            s.push(i);
        }
        while(s.top()!=-1){
            int cur = s.top();
            s.pop();
            maxA = max(heights[cur] *((int)heights.size()-s.top() -1), maxA); 
        }

        return maxA;
    }
};

int main(){
    vector<int> h{2,1,5,6,3,3};
    Solution s;
    cout << s.largestRectangleArea(h)<< endl;

}
