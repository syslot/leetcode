//
// Created by syslot on 21/07/19.
//

#include "../common.h"

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sum = 0;
        ListNode * p = head;
        while(p){
            sum ++;
            p = p->next;
        }
        if(n == sum){
            return head->next;
        }else{
            p = head;
            n = sum - n-1;
            while(n--){
                p = p->next;
            }
            p->next = p->next->next;
        }
        return head;
    }
};

int main(){
    Solution s;
    ListNode * head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);



    ListNode *t = s.removeNthFromEnd(head, 5);
    while(t){
        cout <<t->val << " ";
        t = t->next;
    }

    return 0;
}