#include "../common.h"
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        auto h = new ListNode(0);
        h->next=head;
        ListNode * cur = h, *tail=nullptr, *pos=nullptr;

        for(int i=1;i<m;i++){
            cur = cur->next;
        }

        pos = cur;
        tail = cur->next;
        cur = tail->next;
        for(int i=m+1;i<=n;i++){
            auto nxt = cur->next;
            cur->next = pos->next;
            pos->next = cur;
            cur = nxt;
        }
        tail->next =  cur;
        return h->next;
    }
};

int main(){

    auto h = GenList(vector<int>{1,2,3,4,5});

    Solution s;
    h = s.reverseBetween(h, 4, 5);
    while(h){
        cout << h->val << " ";    
        h=h->next;
    }
    cout << endl;

}
