#include "common.h"



struct ListNode {
      int val;
      struct ListNode *next;
      ListNode(int x) :
            val(x), next(NULL) {
      }
};


class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> s;

        while(head){
            s.push_back(head->val);
            head = head->next;
        }

        reverse(s.begin(), s.end());

        return s;
    }
};

int main(){

    ListNode *head = new ListNode(5);
    head->next = new ListNode(10);
    head->next->next = new ListNode(12);
    head->next->next->next = new ListNode(20);

    Solution s;
    auto v = s.printListFromTailToHead(head);

    for(auto i: v)

        cout << i <<endl;

}
