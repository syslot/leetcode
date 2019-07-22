//
// Created by syslot on 22/07/19.
//

#include "../common.h"

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode * head = new ListNode(0);
        ListNode * cur = head;

        while(lists.size()>1 ) {
            auto check = std::remove_if(
                    lists.begin(),
                    lists.end(),
                    [&](ListNode *h) {
                        return h == NULL ? true : false;

                    });
            lists.erase(check, lists.end());
            if(lists.size() <=1)
                break;

            int q = 0;
            for(int i = 1;i < lists.size();i++){
                if (lists[q]->val > lists[i]->val)
                    q = i;
            }

            cur->next = lists[q];
            cur = cur->next;
            lists[q] = cur->next;

            cur -> next = NULL;


        }

        if(lists.size() == 1)
            cur->next = lists[0];

        return head->next;
    }
};

int main(){

    Solution s;
    vector<ListNode *> lists;

//    lists.push_back(GenList(vector<int>{1,4,5}));
//    lists.push_back(GenList(vector<int>{1,3,4}));
//    lists.push_back(GenList(vector<int>{2,6}));
    lists.push_back(GenList(vector<int>{}));
    lists.push_back(GenList(vector<int>{}));

    auto L = s.mergeKLists(lists);

    while(L){
        cout << L->val << " ";
        L = L->next;
    }

    return 0;

}
