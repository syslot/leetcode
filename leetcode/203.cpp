#include "../common.h"


class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        auto h = new ListNode(0);
        h->next = head;
        auto cur = h;
        while(cur->next){
            if(cur->next->val == val)
                cur->next = cur->next->next;
            else
                cur = cur->next;
        }
        return h->next;
    }
};

int main(){
    auto l = GenList(vector<int>{6,1,2,6,3,4,5,6});
    Solution s;
    l = s.removeElements(l,6);
    while(l){
        cout << l->val << endl; 
        l = l->next;
    }

    return 0;
}
