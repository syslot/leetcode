#include "../common.h"

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head->next == nullptr){
            return head;
        }

        auto h = new ListNode(0);
        h->next = head;

        auto fast = h, slow  = h;

        bool even = false;
        while(true){
            fast = fast->next;
            slow = slow->next;
            if(fast->next)
                fast = fast->next;
            else{
                break;
            }
            if(fast->next == nullptr){
                even = true;
                slow = slow->next;
                break;
            }

        }
        return slow;
        
    }
};

int main(){
    auto h = GenList(vector<int>{1,2});

    Solution s;
    auto h1 = s.middleNode(h);

    while(h1){
        cout << h1->val << " ";
        h1 = h1->next;
    }

    cout << endl;
}
