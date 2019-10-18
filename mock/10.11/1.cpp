#include "../../common.h"


class Solution {
public:
    ListNode* middleNode(ListNode* head) {

        ListNode * h = new ListNode(0);
        h->next = head;

        int count = 0;
        while(h->next){
            count ++;
            h->next = h->next->next;
        }

            count/=2;

        h->next = head;

        while(count -- ){
            h->next = h->next->next;
        }
        return h->next;
        
    }
};

int main(){

    Solution s;
    
    auto head = GenList(vector<int>({1,2,3,4,5}));
    auto l = s.middleNode(head);


    while(l){
        cout<<l->val << " ";
        l = l->next;
    }




}
