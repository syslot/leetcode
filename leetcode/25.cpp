//
// Created by syslot on 22/07/19.
//

#include "../common.h"

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode * l = new ListNode(0), *cur, *dst = new ListNode(0), *tail = dst;
        cur = l->next = head;
        int sum = 0;
        while(cur){
            sum++;
            cur = cur->next;
        }


        while(sum >=k){
            cur = l;
            for(int i =0;i< k;i++){
                cur=cur->next;
            }
            ListNode * tmp = l->next;
            l->next = cur->next;
            cur->next = NULL;

            auto info = reverse(tmp);

            tail->next = std::get<0>(info);
            tail = std::get<1>(info);
            sum -=k;
        }

        if(sum != 0){
            tail->next = l->next;
        }

        return dst->next;
    }

    std::tuple<ListNode *, ListNode *>  reverse(ListNode *head){

        ListNode * h = new ListNode(0), *cur = head, *tail = head;

        while(head){
            cur = head;
            head = head->next;

            cur->next = h->next;
            h->next = cur;

        }
        cur = h->next;
        delete h;

        return make_tuple(cur, tail);
    }
};

int main(){
    Solution s;

    auto l = GenList(vector<int>{1,2,3,4,5});

    auto t = s.reverseKGroup(l, 2);
    while(t){
        cout << t->val << " ";
        t = t->next;
    }
    cout << endl;

    l = GenList(vector<int>{1,2,3,4,5});
    t = s.reverseKGroup(l, 3);
    while(t){
        cout << t->val << " ";
        t = t->next;
    }
    cout << endl;

    return 0;
}