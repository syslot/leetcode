#include "../common.h"


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        if(!head || head->next == NULL)
            return head;

        auto h = new ListNode(0);
        h->next= head;

        int f=h->next->val;

        h = h->next;
        while(h->next){
            if(h->next->val == f)
                h->next = h->next->next;
            else{
                f=h->next->val;
                h = h->next;
            }
        }
        return head;
        
    }
};

int main(){

    auto h = GenList(vector<int> {1,1,2,3,3,4,8,9,10,10,10});

    Solution s;
    h =s.deleteDuplicates(h);

    while(h){
        cout << h->val << " ";
        h=h->next;
    }
    cout << endl;


}
