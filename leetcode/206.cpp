#include "../common.h"


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        auto revP = new ListNode(0);
        auto cur = new ListNode(0);
        cur -> next = head;
        while(cur->next){
            auto p = cur->next;
            cur->next = p->next;

            p->next= revP->next;
            revP->next = p;
        }
        return revP->next;
    }
};

int main(){

    auto p = GenList(vector<int>{1,2,3,4,5});
    Solution s;

    p = s.reverseList(p);
    while(p){
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;



}
