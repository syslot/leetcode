//
// Created by syslot on 22/07/19.
//


#include "../common.h"

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode * h = new ListNode, * cur = h, *tmp = NULL;

        h->next = head;

        while(cur){
            if(cur->next && cur->next->next){
                tmp = cur->next;
                cur->next = tmp->next;
                tmp->next = cur->next->next;
                cur->next->next = tmp;
                cur = cur->next->next;
            }else
                break;
        }
        return h->next;
    }
};

int main(){
    Solution s;

//    auto l = GenList(vector<int>{1,2,3,4});

    auto l = GenList(vector<int>{});

    l = s.swapPairs(l);

    while(l)
    {
        cout << l->val << " ";
        l=l->next;
    }

}