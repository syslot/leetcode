#include "../common.h"

class Solution {
public:
    void reorderList(ListNode* head) {
        if(head==nullptr || head->next == nullptr || head->next->next == nullptr)
            return;
        deque<ListNode *> vhs;
        auto cur = head;
        while(cur){
            vhs.push_back(cur);
            cur = cur->next;
        }

        cur = new ListNode(0);
        while(!vhs.empty()){
            cur->next = vhs.front();
            vhs.pop_front();
            cur=cur->next;
            if(!vhs.empty())
            {
                cur->next = vhs.back();
                vhs.pop_back();
                cur = cur->next;
            }
        }
        cur->next = nullptr;
    }
};

int main(){

    auto h = GenList(vector<int>{1,2,3,4,5,6});
    Solution s;
    s.reorderList(h);
    while(h){
        cout << h->val << " ";
        h = h->next;
    }
    return 0;

}
