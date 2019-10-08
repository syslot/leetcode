//
// Created by syslot on 2019/9/16.
//

#include "../common.h"

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode * src = new ListNode(0), * rst = new ListNode(0);
        src->next = head->next;
        head->next = NULL;
        rst->next = head;

        while(src->next){
            ListNode * tmp = src->next;
            src->next = src->next->next;
            tmp->next = NULL;

            ListNode * idx = rst;
            while(idx->next && tmp->val > idx->next->val){
                idx = idx->next;
            }
            tmp->next = idx->next;
            idx->next = tmp;
        }
        return rst->next;

    }
};

int main(){

    auto l = GenList(vector<int>{-1,5,3,4,0});

    Solution s ;
    l = s.insertionSortList(l);
    while(l!= NULL){
        cout << l->val << " ";
        l = l->next;
    }

}