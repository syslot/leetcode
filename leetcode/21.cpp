//
// Created by syslot on 21/07/19.
//

#include "../common.h"

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;

        ListNode * head = new ListNode(0);
        ListNode * cur = head;
        while(l1 && l2){
            if(l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            }else{
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if(l1 == NULL)
            cur->next = l2;
        else
            cur->next = l1;

        return head->next;

    }
};

int main(){
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);


    ListNode *l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    Solution s;
    auto l = s.mergeTwoLists(l1, l2);

    while(l){
        cout << l->val << " ";
        l = l->next;
    }

    return 0;
}