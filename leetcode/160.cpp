#include "../common.h"

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * pA = new ListNode(0);
        ListNode * pB = new ListNode(0);

        pA->next = headA;
        pB->next = headB;

        int c1=0, c2=0;

        auto p = pA;
        while(p->next){
            c1++;
            p=p->next;
        }
        p=pB;
        while(p->next){
            c2++;
            p=p->next;
        }

        if(c1 > c2){
            int res = c1 -c2;
            while(res--){
                pA = pA->next;
            }
        }else{
            int res = c2 - c1;
            while(res --){
                pB = pB->next;
            }
        }

        ListNode * ptr = NULL;
        while(pA->next){
            if(pA->next == pB->next){
                return pA->next;
            }
            pA = pA->next;
            pB = pB->next;
        }

        return NULL;


        
    }
};

int main(){
    auto p1 = GenList(vector<int>{4,1,8,4,5});
    auto p2 = GenList(vector<int>{5,0,1,8,4,5});

    Solution s;
    auto p = s.getIntersectionNode(p1->next, p2->next);
    cout << p->val<<endl;



}
