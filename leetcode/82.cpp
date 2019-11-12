#include "../common.h"


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr || head->next == nullptr)
            return head;

        ListNode * h = new ListNode(0);
        ListNode * tail = h;
        ListNode * cur = nullptr;

        bool del = false;

        while(head){
            if(cur == nullptr){
                cur = head;
                head = head->next;
            }else{
                if(head->val == cur->val){
                    del = true;
                    head = head->next;
                }else{
                    if(del){
                        cur = head;
                        del = false;
                    }else{
                        tail->next = cur;
                        tail = tail->next;
                        cur = head;
                    }
                    head = head->next;
                }
            }
            
        }
        if(!del){
            tail->next = cur;
            cur->next = nullptr;
        }else{
            tail->next = nullptr;
        }
        
        return h->next;
    }
};


int main(){

    auto head = GenList(vector<int>{1,2,2});

    Solution s;
    auto h = s.deleteDuplicates(head);

    while(h){
        cout << h->val << " ";
        h = h->next;
    }
    cout <<endl;


}
