#include "../common.h"

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        auto h = new ListNode(0);
        h->next = head;
        auto c = h;
        int len = 0;
        while(c->next){
            len++;
            c=c->next;
        }
        c->next = h->next;
        k%=len;
        k = len - k;
        while(--k){
            h->next = h->next->next;
        }
        c = h->next->next;
        h->next->next= NULL;
        return c;
    }
};

int main(){

    auto L = GenList(vector<int>({1,2,3,4,5}));

    Solution s;
    
    L = s.rotateRight(L, 4);
    while(L){
        cout << L->val<<" ";
        L = L->next;
    }
    
    cout << endl;

}
