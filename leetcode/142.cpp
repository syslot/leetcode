#include "../common.h"

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        if(!head)
            return NULL;
        auto l1 = head, l2 = head;
        if(l1->next == NULL)
            return NULL;
        else
            l1=l1->next;
        
        if(!l2->next||!l2->next->next)
            return NULL;
        else
            l2 = l2->next->next;
        while(l1 != l2->next){
            if( !l1->next )
                return NULL;
            else
                l1 = l1->next;
            if( !l2->next && !l2->next->next)
                return NULL;
            else
                l2 = l2->next->next;
        }
        return l1;
        
    }

};

int main(){
    
    auto h = GenList(vector<int>{1,2,3,4}); 
    //h->next->next = h;
    h->next->next->next->next = h->next;

    Solution s;
    auto l = s.detectCycle(h);
    if(l)
        cout << l->val << endl;
    else 
        cout << "NULL" << endl;

}
